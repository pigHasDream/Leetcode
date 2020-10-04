class LFUCache {
  unordered_map<int,int> key2value_;
  unordered_map<int,int> key2freq_;
  unordered_map<int,list<int>> freq2list_;
  unordered_map<int,list<int>::iterator> key2iter_;
  
  const int cap_;
  int minFreq_;
  
public:
  LFUCache(int capacity):
  cap_(capacity),
  // TODO
  minFreq_(0)
  { }

  int get(int key) {
    if(key2value_.count(key) == 0)
      return -1;
    
    int ret = key2value_[key];
    
    int freq = key2freq_[key];
    freq2list_[freq].erase(key2iter_[key]);
    // When freq == minFreq_ and it's the last element
    // We update the minFreq_
    if(minFreq_ == freq and freq2list_[freq].empty()) {
      freq2list_.erase(freq);
      ++minFreq_;
    }
    
    freq2list_[freq+1].emplace_back(key);
    key2iter_[key] = prev(freq2list_[freq+1].end());
    key2freq_[key] = freq+1;

    return ret;
  }

  
  void put(int key, int value) {
    
    if(cap_ == 0) return;
    if(get(key) != -1) {
      key2value_[key] = value;
      return; 
    }

    // evict
    if(key2value_.size() == cap_) {
      int toRemoveKey = freq2list_[minFreq_].front();
      key2value_.erase(toRemoveKey);
      key2freq_.erase(toRemoveKey);
      key2iter_.erase(toRemoveKey);
      freq2list_[minFreq_].pop_front(); 
      if(freq2list_[minFreq_].empty())
        freq2list_.erase(minFreq_);
    }
    
    // add new value
    minFreq_ = 1;
    key2value_[key] = value;
    freq2list_[1].emplace_back(key);
    key2freq_[key] = 1;
    key2iter_[key] = prev(freq2list_[1].end());
  }
};


/*

a. put 
  1. insert new elem, cap is not reached
  2. insert new elem, cap is reached, need to evict one elem
  3. not new elem, alrady exists, just update freq, order, and value
  
b. get
  1. if elem is not in cache, return -1
  2. if elem is in, return, and update freq and order
      i) remove key from original list
      ii) append it to freq+1 list
      iii) key2freq update
      iv) key2iter update
      v) freq2list update (if list is empty)


freq2   
(key1 key2) 

freq3
(key3 key4)   -> key4

freq4
(key5 key6)


freq -> list
keys -> values
key  -> freq
key -> iter





















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
