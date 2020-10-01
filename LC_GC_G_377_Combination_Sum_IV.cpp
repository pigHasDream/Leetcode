// knapsack problem to count the total ways of doing the target sum
class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    const int sz = nums.size();
    vector<unsigned> dp(target+1, 0);
    dp[0] = 1;
    
    // Note below 2 loop. We put the target sum as outer loop.
    // This gives all the permutations!
    // If we swap, it gives the combination results! Like LC 518 Coin change 2
    for(int k=1; k<=target; ++k) {
      for(int i=0; i<sz; ++i) {
        if(nums[i]>k) continue;
        dp[k] += dp[k-nums[i]];
      }
    }
    
    return dp.back();
  }
};


// Follow up problem: if negative number is involved, we'd like 
// to have total number of length limit, otherwise we may end up
// with infinite number of length due to 0 loop!

// Below is the plain memo 2D
// -----------------------------------------------------
class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    const int sz = nums.size();
    
    vector<vector<int>> memo(sz, vector<int>(target, -1));
    
    function<int(int,int)> doDFS =
      [&](int idx, int parSum) -> int {
      
      if(idx == sz) return 0;
      if(parSum > target) return 0;
      if(parSum == target) return 1;
    
      int& ans = memo[idx][parSum];
      if(ans != -1) return ans;
      ans = 0;
      
      for(int i=0; i<sz; ++i) {
        ans += doDFS(i, parSum+nums[i]);
      }
      
      return ans;
    };
      
    return doDFS(0,0);
  }
};

// Below is the plain memo 1D
// ----------------------------------------------------
class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    const int sz = nums.size();
    
    vector<int> memo(target, -1);
    
    function<int(int,int)> doDFS =
      [&](int idx, int parSum) -> int {
      
      if(idx == sz) return 0;
      if(parSum > target) return 0;
      if(parSum == target) return 1;
    
      int& ans = memo[parSum];
      if(ans != -1) return ans;
      ans = 0;
      
      for(int i=0; i<sz; ++i) {
        ans += doDFS(i, parSum+nums[i]);
      }
      
      return ans;
    };
      
    return doDFS(0,0);
  }
};
