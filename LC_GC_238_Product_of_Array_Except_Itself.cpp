class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int sz = nums.size();
    vector<int> res(sz, 1);
    
    for(int i=1; i<sz; ++i)
      res[i] = res[i-1]*nums[i-1];
    
    int prod = 1;
    for(int i=sz-1; i>=0; --i) {
      res[i] *= prod;
      prod *= nums[i];
    }

    return res;
  }
};
