class Trie {
  public:
    Trie(): root_(new TrieNode) {}

    // insert a word to trie
    void insert(const string& word) {
      auto p = root_.get();
      for(const auto& c : word) {
        if(p->children_[c-'a'] == nullptr) {
          p->children_[c-'a'] = new TrieNode();
        }
        p = p->children_[c-'a'];
      }
      p->isWord_ = true;
    }


    // search an entire word
    bool search(const string& word) const {
      const auto ptr = find(word);
      return ptr and ptr->isWord_;
    }

    // check if exists word start with
    bool startWith(const string& prefix) const {
      const auto ptr = find(prefix);
      return ptr != nullptr;
    }

  private:
    // Trie node
    struct TrieNode {

      TrieNode(): isWord_(false), children_(26, nullptr) {}
      ~TrieNode() {
        for(auto cptr : children_)
          delete cptr; 
      }

      bool isWord_;
      vector<TrieNode*> children_;
    };

    // common util function
    const TrieNode* find(const string& word) const {
      const auto& p = root_.get();
      for(const auto& c : word) {
        p = p->children_[c-'a'];
        if(p == nullptr) break;
      }
      return p;
    }

    std::unique_ptr<TrieNode> root_;
};
