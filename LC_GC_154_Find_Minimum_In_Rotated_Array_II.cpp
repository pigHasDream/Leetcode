class Solution {
public:
  int findMin(vector<int>& nums) {
    int left = 0, right = nums.size()-1;
    
    // This solution can solve both LC153 and LC154
    while(left < right) {
      
      int mid = left + (right-left)/2;
      
      if(nums[mid] < nums[left]) {
        right = mid;
      }
      else if(nums[mid] > nums[right]) {
        left = mid+1;
      }
      else
        // find minimum, so we need to reduce right
        --right;
    }

    return nums[left];
  }
};




