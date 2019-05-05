class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int row = matrix.size();
    if(row == 0) return 0;
    int col = matrix[0].size();
    
    vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
    int maxLen = 0;
    
    for(int i=1; i<=row; ++i) {
      for(int j=1; j<=col; ++j) {
        // This state transition is very tricky!!
        if(matrix[i-1][j-1] == '1') {
           dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
           maxLen = max(maxLen, dp[i][j]);
        }
      }
    }
  
  return maxLen*maxLen;
  }
};
