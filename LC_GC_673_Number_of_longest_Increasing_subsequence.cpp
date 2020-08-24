class Solution {
public:
  int findNumberOfLIS(vector<int>& nums) {
    
    int sz = nums.size();
    if(sz == 0) return 0;
    
    vector<int> dp(sz, 1);
    vector<int> count(sz, 1);
    
    int maxLen = 1;
    for(int i=0; i<sz; ++i) {
      for(int j=0; j<i; ++j) {
        if(nums[i] > nums[j]) {
          if(dp[i] < dp[j]+1) {
            // first time sees current larget length!
            // just take the j-th value!
            // clear the earlier value!
            dp[i] = dp[j]+1;
            count[i] = count[j];
          }
          else if(dp[i] == dp[j] + 1) {
            // now we see it multiple times,
            // each time we add the count up!
            count[i] += count[j];
          }
        }
      }
      maxLen = max(maxLen, dp[i]);
    }
      
    int res = 0;
    for(int i=0; i<sz; ++i)
      if(dp[i] == maxLen) 
        res += count[i];
    
    return res;
  }
};
