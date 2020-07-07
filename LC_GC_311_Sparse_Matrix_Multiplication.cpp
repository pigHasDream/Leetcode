class Solution {
public:
  vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    unordered_map<int, vector<pair<int,int>>> valA; 
    unordered_map<int, vector<pair<int,int>>> valB; 
    vector<vector<int>> res(A.size(), vector<int>(B.front().size(), 0));
    
    for(int i=0; i<A.size(); ++i) {
      for(int j=0; j<A.front().size(); ++j) {
        if(A[i][j])
          valA[i].emplace_back(j, A[i][j]);
      }
    }
    
    for(int i=0; i<B.size(); ++i) {
      for(int j=0; j<B.front().size(); ++j) {
        if(B[i][j])
          valB[i].emplace_back(j, B[i][j]);
      }
    }
    
    for(int i = 0; i < A.size(); ++i)
      for(auto& [k,a] : valA[i])
        for(auto& [j,b] : valB[k])
              res[i][j] += a*b;
    
    return res;
    
  }
};
