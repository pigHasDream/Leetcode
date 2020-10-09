class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int S) {
    
    // pos - neg = S
    // pos + pos - neg = S + pos
    // 2*pos = S + pos + neg
    // pos = (S + sum(nums)) / 2;
    // Now it converts to a subset sum problem!
    
    int sum = accumulate(nums.begin(), nums.end(), 0);
    
    if(sum < S or (sum+S)%2) return 0;
    int target = (sum+S) >> 1;
    
    vector<int> dp(target+1, 0);
    dp.front() = 1;
    
    // This is the backward 1-D dp.
    for(int j=0; j<nums.size(); ++j) 
      for(int i=target; i>=nums[j]; --i)
        dp[i] += dp[i-nums[j]];
    
    return dp.back();
  }
};



class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int S) {
    
    const int sz = nums.size();
    
    vector<unordered_map<int,int>> memo(sz);
      
    function<int(int,int)> doDFS
      = [&](int idx, int curSum) -> int {
      
      if(idx == sz) {
        return curSum == S;
      }
      
      if(memo[idx].count(curSum))
        return memo[idx][curSum];
      
      int& ans = memo[idx][curSum] = 0;
      
      ans = doDFS(idx+1, curSum + nums[idx]) + 
            doDFS(idx+1, curSum - nums[idx]);
      
      return ans;
    };

    return doDFS(0, 0);
  }
};
