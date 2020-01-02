class Solution {
public:
  int countSquares(vector<vector<int>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    
    vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
    // The key trick is to use the ANCHOR right bottom cell to test for all square cells
    // the largest side size square anchored at this cell EQUALS to the number of square cells
    
    int res = 0;
    for(int i=1; i<=row; ++i) {
      for(int j=1; j<=col; ++j) {
        // only when the anchor cell is 1, we do this change, otherwise we can directly skip it!
        if(matrix[i-1][j-1]) {
          dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
          res += dp[i][j];
        }
      }
    }

    return res;
  }
};
