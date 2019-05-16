class MyHashMap {
  vector<list<pair<int, int>>> hash_;
  static constexpr int n_ = 1000;
  
public:
  /** Initialize your data structure here. */
  MyHashMap() {
    hash_.resize(n_);
  }

  /** value will always be non-negative. */
  void put(int key, int value) {
    auto& lst = hash_[key%n_];
    for(auto& p : lst) {
      if(p.first == key) {
        p.second = value;
        return;
      }
    }
    lst.emplace_back(key, value);
  }

  /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
  int get(int key) {
    const auto& lst = hash_[key%n_];
    for(const auto& p : lst) {
      if(p.first == key) {
        return p.second;
      }
    }

    return -1;
  }

  /** Removes the mapping of the specified value key if this map contains a mapping for the key */
  void remove(int key) {
    auto& lst = hash_[key%n_];

    // We can either use remove_if with lambda
    // or just plain remove. 
    //lst.remove_if([key](auto p) {return p.first == key;});

    // removing element in a loop needs to conditionally increase the 
    // iter!! 
    for(auto iter = lst.begin(); iter!=lst.end();) {
      if(iter->first == key) {
        lst.remove(*iter);
        return;
      }
      else {
       ++iter;
      }
    }


  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
