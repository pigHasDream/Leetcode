class Solution {

  public:
    int maxSubArraySum(vector<int>& nums) {
      int res = INT_MIN;
      int cur = 0;

      // It applies to postive and negative numbers 
      // and the final length of max sub array is flexible
      
      // cur holds so far accumulated sum, but 
      // reset to 0 if it's negative, because
      // start over from the next node is always better!
      // Otherwise, we just keep accumulating.
      for(const auto& n : nums) {
        cur = n + max(0, cur);
        res = max(res, cur);
      }

      return res;
    }
};

