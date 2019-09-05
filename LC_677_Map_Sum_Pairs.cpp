class MapSum {
public:
  /** Initialize your data structure here. */
  MapSum() : root_() { }

  void insert(string key, int val) {
    auto ptr = &root_;
    for(const auto& c : key) {
      if(ptr->kids_.count(c) == 0) {
        ptr->kids_[c] = new TrieNode;
      }
      ptr = ptr->kids_[c];
    }
    
    ptr->isWord_ = true;
    ptr->sum_ = val;
  }

  int sum(string prefix) {
    auto ptr = &root_;
    int res = 0;
    
    // below checks for the full prefix! 
    for(const auto& c : prefix) {
      if(ptr->kids_.count(c) == 0) return 0;
      ptr = ptr->kids_[c];
    }
    
    // now once the full prefix is done checking
    // we start to account for sums as long as it's marked as isWord_
    // this is a standard adjacency list DFS traversal.
    function<void(const TrieNode*)> doDFS = [&](const TrieNode* node) {
      if(node == nullptr) return;
      
      if(node->isWord_) 
        res += node->sum_;
      
      for(const auto& k : node->kids_) {
        doDFS(k.second);
      }
    };
    
    doDFS(ptr);
    
    return res;
  }
  
private:
  struct TrieNode {
    TrieNode() = default;
    ~TrieNode() {
      for(auto& k : kids_)
        delete k.second;
    }
    
    unordered_map<char, TrieNode*> kids_; 
    bool isWord_{false};
    int sum_{0};
  };
  
  TrieNode root_;
  
};
