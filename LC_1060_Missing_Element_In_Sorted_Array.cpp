class Solution {
public:
  int missingElement(vector<int>& nums, int k) {
    
    int left = 0, right = nums.size();
    int miss = 0;
    
    while(left < right) {
      int mid = left + (right-left)/2;
      
      miss = nums[mid] - nums.front() - mid;
        
      if(miss >= k) {
        right = mid;
      }
      else {
        left = mid+1;
      }
    }

    return nums.front()+left+k-1;
  }
};
