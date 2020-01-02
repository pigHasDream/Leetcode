class Solution {
public:
  vector<int> pathsWithMaxScore(vector<string>& board) {
    const int mod = 1000000000+7;
    
    // padding 0 to make the check easier!!
    const int m = board.size();
    const vector<pair<int,int>> dir = {{1,0}, {0,1}, {1,1}};
    
    vector<vector<int>> cost(m+1, vector<int>(m+1, 0));
    vector<vector<int>> path(m+1, vector<int>(m+1, 0));
    board[m-1][m-1] = board[0][0] = '0';
    path[0][0] = 1;
    
    for(int i=1; i<=m; ++i) {
      bool hasAPath = false;
      for(int j=1; j<=m; ++j) {
        if(board[i-1][j-1] != 'X') {
          for(const auto& d : dir) {
            int pX = i - d.first;
            int pY = j - d.second;
            
            if(path[pX][pY]) {
              int val = board[i-1][j-1] - '0' + cost[pX][pY];
              if(val >= cost[i][j]) {
                path[i][j] = ((val == cost[i][j] ? path[i][j] : 0) + path[pX][pY])%mod;
                cost[i][j] = val;
                hasAPath = true;
              }
            }
          }
        }
      }
      if(not hasAPath) break;
    }
    
    return { cost[m][m], path[m][m] };
  }
};
