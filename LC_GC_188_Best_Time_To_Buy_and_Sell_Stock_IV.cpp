class Solution {
public:
  int maxProfit(int k, vector<int>& prices) {
    
    int res = 0;
    
    if(2*k > prices.size()) {
      for(int i=1; i<prices.size(); ++i)    
        res += max(0, prices[i] - prices[i-1]);
      
      return res;
    }
    
    // [0]: empty 
    // [1]: hold 
    vector<vector<array<int, 2>>> dp(k+1, vector<array<int,2>>(prices.size(), {0,-prices.front()}));
    
    for(int j=1; j<=k; ++j) {
      for(int i=1; i<prices.size(); ++i) {
        dp[j][i][0] = max(dp[j][i-1][0], dp[j][i-1][1] + prices[i]);
        dp[j][i][1] = max(dp[j-1][i][0] - prices[i], dp[j][i-1][1]);
      }
    }
    
    return dp[k].back().front();

  }
};
