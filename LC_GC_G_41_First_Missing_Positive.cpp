class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    // Swap the value to its "correct" position
    
    for(int i=0; i<nums.size(); ) {
      if(nums[i]>0 and nums[i]<=nums.size() and
         nums[i]!=nums[nums[i]-1]) {
        swap(nums[i], nums[nums[i]-1]);
      }
      else ++i;
    }
    
    for(int i=0; i<nums.size(); ++i) {
      if(nums[i] != i+1) return i+1;
    }

    return nums.size()+1;
  }
};
