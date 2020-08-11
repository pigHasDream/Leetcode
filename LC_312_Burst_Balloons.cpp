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

// Key things are
// Padding two ends to have a uniform approach
// State transition: scan through the surviving node, and will multiple by the one elem
// passing the boundaries.
class Solution {
public:
  int maxCoins(vector<int>& nums) {
    vector<int> balls(nums);
    balls.insert(balls.begin(), 1);
    balls.emplace_back(1);
    
    int sz = balls.size();
    vector<vector<int>> memo(sz, vector<int>(sz, -1));
    
    function<int(int,int)> doDFS =
      [&](int left, int right) {
      
      if(left > right)
        return 0;
      
      if(memo[left][right] != -1)
        return memo[left][right];
        
      int ret = 0;
      for(int i=left; i<=right; ++i) {
        ret = max(ret, doDFS(left, i-1) + doDFS(i+1, right) + balls[left-1]*balls[i]*balls[right+1]);
      }
      
      return memo[left][right] = ret;
    };
    
    return doDFS(1, sz-2);
    
  }
};
