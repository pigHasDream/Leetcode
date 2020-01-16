class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    
    vector<vector<string>> res;
    vector<pair<int,int>> rawSol; 
    
    auto assemble = [n](const vector<pair<int,int>>& rawSol,
                         vector<string>& curSol) {
      
      for(const auto& p : rawSol) {
        curSol[p.first][p.second] = 'Q';
      }  
    };
    
    auto isOK = [n](const int i, const int j, 
                   const vector<pair<int,int>>& rawSol) {
      for(const auto& p : rawSol) {
        if(p.first == i or p.second ==j or 
           (abs(p.first-i) == abs(p.second-j))) {
          return false;
        }
      }
      return true;
    };
    
    function<void(int,int)> doBackTrack = [&](int count, int row) {

      if(count == 0) {
        vector<string> curSol(n, string(n,'.'));
        assemble(rawSol, curSol);
        res.emplace_back(curSol);
        return;
      }
      
      if(row == n) return;
      
      for(int j=0; j<n; ++j) {
        if(isOK(row,j,rawSol)) {
          rawSol.emplace_back(row,j);
          doBackTrack(count-1, row+1);
          rawSol.pop_back();
        }     
      }
      
    };
    
    doBackTrack(n, 0);
    
    return res; 
  }
};
