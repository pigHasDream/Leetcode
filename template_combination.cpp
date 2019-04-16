class Solution {
public:
  // return combination k out of 1...n
  vector<vector<int>> combine(int n, int k) {
    
    vector<vector<int>> res;
    vector<int> curSol;

    // int i = 0 and this makes the next 
    // recursion starts from 1. Good!
    recurBackTrace(res, curSol, n, k, 0);
    
    return res;
  }
  
  void recurBackTrace(vector<vector<int>>& res, 
                      vector<int>& curSol, 
                      const int n, 
                      const int k, 
                      int i) {
    
    if(curSol.size() == k) {
      res.emplace_back(curSol);
      return;
    }
    
    for(int j=i+1; j<=n; ++j) {      
      curSol.emplace_back(j);
      recurBackTrace(res, curSol, n, k, j);
      curSol.pop_back();
    }
  }
  
};
