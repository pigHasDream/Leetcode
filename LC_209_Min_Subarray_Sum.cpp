iclass Solution {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int sum = 0;
    int left = 0;
    int res = INT_MAX;
    
    // outer loop extends the right boundary
    for(int right = 0; right < nums.size(); ++right) {
      // first if-check is for satisfactory
      if(sum < s) {
        sum += nums[right];
      }
      
      // below loop is to shrink left boundary
      // Condition can be opposite to earlier one!
      while(sum >= s) {
        // This result update is dependent on the 
        // either min or max!
        res = min(res, right-left+1);
        sum -= nums[left];
        ++left;
      }
    }

    return res == INT_MAX ? 0 : res;
  }
};


class Solution {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    if(nums.size() == 0) return 0;
    
		// note the prefix sum needs one more padding
    // due to 0 elements considered.
    vector<int> prefixSum(nums.size()+1, 0);
    
    for(int i=0; i<nums.size(); ++i)
      prefixSum[i+1] = prefixSum[i] + nums[i];
    
    int left = 0;
    int minLen = INT_MAX;
    for(int right = 1; right < nums.size()+1; ++right) {
      while(prefixSum[right] - prefixSum[left] >= s) {
        if(minLen > right - left) {
          minLen = right - left;
        }
        ++left;
      }
    }
    
    return minLen == INT_MAX ? 0 : minLen;
  }
};
