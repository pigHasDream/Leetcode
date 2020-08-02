class LRUCache {
  int cap_;
  // store pair<value, iter>
  unordered_map<int, pair<int,list<int>::iterator>> cache_;
  // store key
  list<int> order_;
  
  void evict() {
    int key = order_.back();
    order_.pop_back();
    cache_.erase(key);
  }
    
  void update(int key, int value) {
    order_.erase(cache_[key].second);
    order_.emplace_front(key);
    cache_[key] = {value, order_.begin()};
  }
  
public:
  LRUCache(int capacity) 
  : cap_(capacity),
    cache_(),
    order_(){
  }

  int get(int key) {
    if(cache_.count(key)) {
      int value = cache_[key].first;
      update(key, value);
      return value;
    }
    
    return -1;
  }

  void put(int key, int value) {
    
    if(cache_.count(key)) {
      update(key, value);
      return;
    }
    
    if(order_.size() == cap_)
      evict();
    
    order_.emplace_front(key);
    cache_[key] = {value, order_.begin()};
  }
};
