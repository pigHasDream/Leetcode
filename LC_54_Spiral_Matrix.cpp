class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    if(m==0) return {};
    int n = matrix[0].size();
    if(n==0) return {};
    
    vector<int> nStep {n, m-1};
    vector<vector<int>> dir = { {0,1}, {1,0}, {0,-1}, {-1,0} };
    
    int iDir = 0;
    int ir = 0, ic = -1;
    
    vector<int> res;
    while(nStep[iDir%2]) {
      // we alternate row and col, so mod 2
      for(int i=0; i<nStep[iDir%2]; ++i) {
        ir += dir[iDir][0];
        ic += dir[iDir][1];
        res.emplace_back(matrix[ir][ic]);
      }
      
      --nStep[iDir%2];
      iDir = (iDir+1)%4;
    }
    
    return res;
  }
};
