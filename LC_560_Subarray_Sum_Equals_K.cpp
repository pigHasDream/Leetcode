class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    int res=0;
    int sum=0;
    // the memo stores <sum, count>
    unordered_map<int, int> memo;
    memo[0] = 1;
    
    for(int i=0; i<nums.size(); ++i) {
      sum += nums[i];
      res += memo[sum-k];
      ++memo[sum];
    }
    
    return res;
  }
};
