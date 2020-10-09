class Solution {
public:
  int wiggleMaxLength(vector<int>& nums) {
    const int sz = nums.size();
    if(sz == 0) return 0;
    
    // q records the longest sequence with last seg decreasing
    // p records the longest sequence with last seg increasing
    int p = 1, q = 1;
    
    for(int i=1; i<sz; ++i) {
      
      // the latest nums[i] is higher,
      // then we know for sure, p will see a turn!
      // Hence q+1 = p
      if(nums[i] > nums[i-1]) {
        p = q+1;
      }
      else if(nums[i] < nums[i-1]) {
        q = p+1;
      }
    }

    return max(p,q);
  }
};
