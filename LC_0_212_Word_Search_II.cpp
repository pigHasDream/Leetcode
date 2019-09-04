class Solution {
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    int row = board.size();
    if(row<1) return {};
    int col = board[0].size();
    if(col<1) return {};
    
    unordered_set<string> res;
    TrieNode root;
    
    for(const auto& w : words) {
      auto p = &root;
      for(const auto& c : w) {
        if(p->kids_[c-'a'] == nullptr) 
          p->kids_[c-'a'] = new TrieNode;
        
        p = p->kids_[c-'a'];
      }
      p->isWord_ = true;
    }
    
    vector<vector<int>> visit(row, vector<int>(col, 0));
    vector<int> dir{0,1,0,-1,0};
    
    function<void(int,int,const TrieNode*,string)> doDFS = [&] (int i, int j, const TrieNode* node, string curSol) {
      
      // We use current node's kids_ to check for existence of certain char
      // But use next (kid) node to check for isWord_ mark.
      
      auto next = node->kids_[board[i][j]-'a'];
      if(next == nullptr) return;
      curSol += board[i][j];
      if(next->isWord_) res.emplace(curSol);
      
      visit[i][j] = 1;
      
      for(int m=0; m<4; ++m) {
        int x = i+dir[m];
        int y = j+dir[m+1];
        if(x<0 or y<0 or x>row-1 or y>col-1 or visit[x][y])
          continue;
        doDFS(x,y,next,curSol);
      }
      
      visit[i][j] = 0;
    };
    
    for(int r=0; r<row; ++r) {
      for(int c=0; c<col; ++c) {
        visit.resize(row, vector<int>(col, 0));
        doDFS(r,c,&root,"");
      }
    }
    
    return vector<string>(res.begin(), res.end());
  }
  
private:
  struct TrieNode {
    TrieNode() = default;
    ~TrieNode() {
      for(auto& k : kids_)
        delete k;
    }
    vector<TrieNode*> kids_{26, nullptr};
    bool isWord_{false};
  };
};
