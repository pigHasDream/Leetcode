class Solution {
public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    unordered_map<int, int> lut;
    int res = 0;
    
    // The most tricky part for this problem
    // is the lut[0]. Since there is no such element,
    // we have to extend the value by one.
    
    // Also, for prefix sum, index distance does not
    // need to add 1.
    lut[0] = -1;
    
    for(int i=0, sum=0; i<nums.size(); ++i) {
      sum += nums[i];
      if(lut.count(sum) == 0) lut[sum] = i;
      if(lut.count(sum-k)>0) res = max(res, i - lut[sum-k]);
    }

    return res;
  }
};
