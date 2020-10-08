class Solution {
  struct TrieNode {
    vector<TrieNode*> kids_;
    bool isWord_;
    TrieNode(): kids_(26,nullptr), isWord_(false) {}
    ~TrieNode() {
      for(auto k : kids_)
        if(k) delete k;
    }
  };
  
  class Trie {
      unique_ptr<TrieNode> root_;
    
    public:
      Trie() : root_(new TrieNode) {}
    
      TrieNode* getRoot() { return root_.get(); }
    
      void addWord(const string& word) {
        auto ptr = root_.get();
        for(const auto& c : word) {
          int idx = c-'a';
          if(ptr->kids_[idx] == nullptr)
            ptr->kids_[idx] = new TrieNode;
          ptr = ptr->kids_[idx];
        }
        
        ptr->isWord_ = true;
      }
    
      // This is the key API!
      bool findChain(string word, int index, TrieNode* root, int count) {
        
        // we always takes in the root of the Trie
        auto ptr = root;
        // checking for index of the current word
        // When it hits the end, we should have count > 1
        if(index == word.size()) return count > 1;
        if(ptr == nullptr) return false;
        
        for(int i=index; i<word.size(); ++i) {
          // if the word is not sufficiently searchable
          if(ptr->kids_[word[i]-'a'] == nullptr)
            return false;
          
          ptr = ptr->kids_[word[i]-'a'];
          // Whe we see a isWord_, we need to start back to
          // root pointer and continue search the rest part of the word!
          if(ptr->isWord_ and findChain(word, i+1, root, count+1))
            return true;
        }
        
        return false;
      }
  };
  
  
public:
  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

    Trie theTrie;
    
    for(const auto& word : words)
      theTrie.addWord(word);
    
    vector<string> res;
    for(const auto& word : words) {
      if(theTrie.findChain(word, 0, theTrie.getRoot(), 0)) {
        res.emplace_back(word);
      }
    }
    
    return res;
  }
};
