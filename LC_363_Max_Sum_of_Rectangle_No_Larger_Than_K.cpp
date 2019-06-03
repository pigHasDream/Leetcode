class Solution {
public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int res = INT_MIN;
    
    int row = matrix.size();
    if(row == 0) return res;
    int col = matrix[0].size();
    if(col == 0) return res;
    
    vector<int> colSum(row, 0);
    
    // same as LC_1074.
    // since colums can be larger,
    // we do N^2 to get the bounds of columns
    for(int c=0; c<col; ++c) {
      fill(colSum.begin(), colSum.end(), 0);
      
      for(int j=c; j<col; ++j) {
        // Below is the colum based sum at each row position
        // the entire suming procedure is over the column traverse
        for(int i=0; i<row; ++i) colSum[i] += matrix[i][j];
        
        // below is the standard runnig prefix sum proceudre!
        // we use hash to quickly retrieve any previously 
        // calculated value.
        
        set<int> hash;
        // this 0 means we can have any standalone element meets
        // the requirement
        hash.emplace(0);
        int sum=0;
        
        for(int t=0; t<row; ++t) {
          sum += colSum[t];
          // We need to find the sum - x <= k,
          // so x >= sum - k. 
          // This indicates a lower_bound.
          auto iter = hash.lower_bound(sum-k);
          if(iter!=hash.end()) res = max(res, sum-*iter);
          if(res == k) return k;
          
          hash.emplace(sum);
        }
        
      }
    }
    
    return res;
  }
};
