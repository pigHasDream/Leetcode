class Solution {
public:
  int maxCoins(vector<int>& nums) {
    vector<int> ball(nums);
    ball.insert(ball.begin(), 1);
    ball.emplace_back(1);
    
    // the key insight here is to partition 
    // the balloons by SURVIVING balloons!
    // The good thing is we can well define 
    // the recursion problem!
    
    vector<vector<int>> dp(ball.size(), vector<int>(ball.size(),0));
    
    // Also, the transition funciton is very tricky!
    for(int len=1; len<=nums.size(); ++len) {
      for(int i=1; i<=nums.size()-len+1; ++i) {
        int j = i+len-1;
        for(int k=i; k<=j; ++k) {
          dp[i][j] = max(dp[i][j], dp[i][k-1] + ball[i-1]*ball[k]*ball[j+1] + dp[k+1][j]);
        }
      }
    }
    
    return dp[1][nums.size()];

  }
};
