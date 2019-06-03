class Solution {
public:
  int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();
    
    vector<int> rowSum(col, 0);
    int res = 0;
    for(int r=0; r<row; ++r) {
      
      // clean up the rowSum after all scanning from previous r-th
      fill(rowSum.begin(), rowSum.end(), 0);
      // here it means we start from r-th row,
      // and scan through the end of the matrix
      for(int i=r; i<row; ++i) {
        // first to get current compressed row(s)'s sum at
        // each j-th column.
        // Because, we'll gradually build up the column sum
        // while traversing the rows!
        // So, it accumulates multiple row's sums
        for(int k=0; k<col; ++k) 
          rowSum[k] += matrix[i][k];
        
        // Below is a standard 1-D max subarray sum
        // by using a "running prefixSum" technique!
        unordered_map<int, int> hash;
        hash[0] = 1;
        int sum = 0;
        for(int t=0; t<col; ++t) {
          sum += rowSum[t];
          res += hash[sum - target];
          ++hash[sum];
        }
      }
    }
    
    return res;
  }
};
