class Solution {
public:
  bool canPartition(vector<int>& nums) {
    
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum%2) return false;
    int parSum = sum/2;
    const int sz = nums.size();
    // This is key to try larger number first and prune early!!
    sort(nums.rbegin(), nums.rend());
    
    // this picked is optional if we don't use the nums[i] nums[i-1] check
    vector<int> picked(sz, 0);
    // memo is optional, but good to have!
    vector<vector<int>> memo(sz, vector<int>(sum, -1));
    
    function<bool(int,int)> doDFS =
      [&](int idx, int curSum) {
      if(curSum == parSum) return true;
      // We prune early if not meet! This is KEY!!
      if(curSum > parSum) return false;
      if(idx == sz) return false;
      
      int& ans = memo[idx][curSum];
      if(ans != -1) return ans == 1;
      
      for(int i=idx; i<sz; ++i) {
        if(picked[i]) continue;
        
        // Here it checks if the same value is re-evaluated due to duplication
        // and if earlier we didn't get it, we don't check it again!
        if(i>1 and nums[i] == nums[i-1] and picked[i-1]==0)
          continue; 
        
        picked[i] = 1;
        if(doDFS(i+1, curSum+nums[idx]))
          return true;
        picked[i] = 0;
      }
      
      ans = 0;
      return false;
    };

    return doDFS(0,0);
  }
};
