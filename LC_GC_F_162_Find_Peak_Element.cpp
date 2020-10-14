class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    if(nums.size() == 1) return 0;
    // Here we explicitly take the right end -1
    int left = 0, right = nums.size()-1;
    
    while(left < right) {
      int mid = left + (right - left)/2;
      
      // Because above we have taken out the right most,
      // we can always safely add 1 to the right.
      if(nums[mid] < nums[mid+1])
        left = mid+1;
      else 
        right = mid;
    }

    return right;
  }
};
