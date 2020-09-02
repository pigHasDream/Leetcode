class Solution {
public:
  int maxProduct(vector<int>& nums) {
    
    // Key is to realize we can greedily multiply
    // even number
    // when hit 0, take it as deliminator
    // Otherwise, keep multiply
    // 2-way pass
    int res = INT_MIN;
    
    int prod = 1;
    for(int i=0; i<nums.size(); ++i) {
      res = max(res, prod*=nums[i]);
      if(nums[i]==0) prod = 1;
    }
    
    prod = 1;
    for(int i=nums.size()-1; i>=0; --i) {
      res = max(res, prod*=nums[i]);
      if(nums[i]==0) prod = 1;
    }
    
    return res;
  }
};



// This is similar to Kadane's algo
// Either pick up current value as start,
// or multiply so far positive and negative 
// depending on n~0 relation.
// When hitting a 0, we refresh it.
class Solution {
public:
  int maxProduct(vector<int>& nums) {
    
    int res = INT_MIN;
    int pos = 1;
    int neg = 1;
    int pos_prev = 1;
    int neg_prev = 1;
    
    for(const auto& n : nums) {
      pos = max(n, max(pos_prev*n, neg_prev*n));
      neg = min(n, min(pos_prev*n, neg_prev*n));
      res = max(res, pos);
      pos_prev = n==0 ? 1 : pos;
      neg_prev = n==0 ? 1 : neg;
    }
    
    return res;
  }
};
