class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    int res=0;
    int sum=0;
    // the memo stores <sum, count>
    unordered_map<int, int> memo;
    
    // We are doing a running sum!
    // Basically, we have to use a one-pass
    // loop. At each number, we check its previous
    // subarray's sum!
    // We cannot do a 2-pass scan, as it won't
    // correctly set the count. 
    // prefixSum is based on its previous sums,
    // so when count the res, we have to do it 
    // during the scanning.
    
    memo[0] = 1;
    for(const auto &n : nums) {
      sum += n;
      res += memo[sum-k];
      ++memo[sum];
    }
    
    return res;
  }
};
