// -----------------------------------------------------
struct TrieNode {
  TrieNode() : kids_(26, nullptr), isWord_(false) {}
  ~TrieNode() {
    for(auto& ptr : kids_)
      delete ptr;
  }
  vector<TrieNode*> kids_;
  bool isWord_; 
};

// -----------------------------------------------------
class Trie {
public:
  TrieNode theRoot_;
  Trie(): theRoot_() {}
  
  void insert(const string& word) {
    auto p = &theRoot_;
    for(const auto& c : word) {
      if(p->kids_[c-'a'] == nullptr) 
        p->kids_[c-'a'] = new TrieNode();
      p = p->kids_[c-'a'];
    }
    p->isWord_ = true;
  }
};

// -----------------------------------------------------
class Solution {
  Trie theTrie_;
  unordered_set<string> res_;
  vector<vector<bool>> visit_;
  vector<int> dir_{0,1,0,-1,0};
  
public:
  vector<string> findWords(vector<vector<char>>& board, 
                           vector<string>& words) {
    int row = board.size();
    if(row == 0) return {};
    int col = board[0].size();
    
    visit_.resize(row, vector<bool>(col, false));
    for(const auto& w : words) 
      theTrie_.insert(w);
    
    auto ptr = &(theTrie_.theRoot_);
    
    // After setting up the Trie, we can 
    // scan based on board and check each existing 
    // Trie path. 
    // The good thing about this is the early 
    // pruning based on the prefix.

    for(int i=0; i<row; ++i) {
      for(int j=0; j<col; ++j) {
        visit_[i][j] = true;
        doDFS(board, ptr, "", i, j);
        visit_[i][j] = false;
      }
    }
    return vector<string>(res_.begin(), res_.end());
  }
  
private:
  void doDFS(const vector<vector<char>>& board,
             TrieNode* nodePtr,
             string curWord,
             int i,
             int j) {
    
    auto next = nodePtr->kids_[board[i][j] - 'a'];
    
    // if there is no more char in this Trie path, ends it.
    if(next == nullptr) return;
    
    // otherwise, continue searching the same Trie path.
    curWord += board[i][j];
    nodePtr = next;
    
    // even if it's a word and found, we continue the search.
    // Since multiple words can share the same prefix.
    if(nodePtr->isWord_) res_.insert(curWord);
    
    for(int k=0; k<4; ++k) {
      int xx = i+dir_[k], yy = j+dir_[k+1];
      
      if(xx<0 or xx>board.size()-1 or 
         yy<0 or yy>board[0].size()-1 or 
         visit_[xx][yy]) 
        continue;
     
      visit_[xx][yy] = true;
      doDFS(board, next, curWord, xx, yy);
      visit_[xx][yy] = false;
    }
  }
  
};
