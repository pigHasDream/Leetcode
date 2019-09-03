class MagicDictionary {
public:
  /** Initialize your data structure here. */
  MagicDictionary(): root_(new TrieNode) {
  }

  /** Build a dictionary through a list of words */
  void buildDict(vector<string> dict) {
    auto ptr = root_.get();
    for(const auto& w : dict) {
      ptr = root_.get();
      for(const auto& c : w) {
        if(ptr->kids_[c-'a'] == nullptr) {
          ptr->kids_[c-'a'] = new TrieNode;
        }
        ptr = ptr->kids_[c-'a'];
      }
      ptr->isWord_ = true;
    }
  }

  /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
  bool search(string word) {
    // Exhaustively check for flipping one of the node and then try to match in dictionanry!
    for(auto& c : word) {
      auto orig = c;
      for(int i=0; i<26; ++i) {
        char n = char('a' + i); 
        if(n == c) continue;
        c = n;
        if(find(word)) return true;
        c = orig;
      }
    }
    
    return false;
  }
  
private:
  struct TrieNode {
    vector<TrieNode*> kids_{26, nullptr};   
    bool isWord_{false};
  };
  
  bool find(string word) {
    auto rt = root_.get();
    for(const auto& c : word) {
      if(rt->kids_[c-'a'] == nullptr) {
        return false;
      }
      rt = rt->kids_[c-'a'];
    }
    return rt and rt->isWord_;
  }
  
  unique_ptr<TrieNode> root_;
};
