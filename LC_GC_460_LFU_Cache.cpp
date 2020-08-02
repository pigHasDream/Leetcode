class LFUCache {
  int cap_;
  int minFreq_;
  // key -> <value, freq>
  unordered_map<int, pair<int,int>> data_;
  // freq -> list, and list element stores the key!
  unordered_map<int, list<int>> freqMap_;
  // key -> list::iter 
  unordered_map<int, list<int>::iterator> iterMap_;
  
  // remove the least freq last used one
  // no freq or minFreq_ update yet.
  void evict() {
    auto& lst = freqMap_[minFreq_];
    auto iter = lst.rbegin(); 
    data_.erase(*iter);
    iterMap_.erase(*iter);
    lst.pop_back();
  }
  
  // freq update, minFreq_ update
  void update(int key, int freq) {
    freqMap_[freq].erase(iterMap_[key]);
    iterMap_.erase(key);
    data_[key].second += 1;
    freqMap_[freq+1].emplace_front(key);
    iterMap_[key] = freqMap_[freq+1].begin();
    
    if(freq == minFreq_ and freqMap_[freq].empty()) 
      ++minFreq_;
  }
  
public:
  LFUCache(int capacity): 
  cap_(capacity),
  minFreq_(0),
  data_(),
  freqMap_(),
  iterMap_()
  {}

  int get(int key) {
    if(data_.count(key) == 0)
      return -1;
    
    // existing freq dont touch
    auto [value, freq] = data_[key];
    // update freq by one
    update(key, freq);

    return value;
  }

  void put(int key, int value) {
    if(cap_ == 0)
      return;
    
    if(data_.count(key) == 0) {
      if(data_.size() == cap_) {
        evict();
      }
      // here put the initial freq = 0 for new data
      data_[key] = {value, 0};
      freqMap_[0].emplace_front(key);
      iterMap_[key] = freqMap_[0].begin();
      // set minFreq_ = 0 for now, and use coverged update() to do increment
      minFreq_ = 0;
    }
    else {
      // do not update freq yet
      data_[key].first = value; 
    }
    
    // update freq by one
    update(key, data_[key].second);
  }
};
