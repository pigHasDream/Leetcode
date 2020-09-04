class Solution {
public:
  int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if(k == 0) 
      return 0;
       
    int left = 0;
    int res = 0;
    int prod = 1;
      
    for(int i=0; i<nums.size(); ++i) {
      
      prod *= nums[i];
      while(left <= i and prod >= k) {
        prod /= nums[left++];
      }
      
      res += i-left+1;
    }
     
    return res;
  }
};
