// The version 2 to return if holds the number
// There may be duplications on the numbers.

class Solution {
public:
  bool search(vector<int>& nums, int target) {
    
    int left = 0; int right = nums.size()-1;
    
    while(left <= right) {
      
      int mid = left + (right - left)/2;
      if(nums[mid] == target)
        return true;
      
      if(nums[left] < nums[mid])
        if(target < nums[mid] and target >= nums[left]) 
          right = mid - 1;
        else
          left = mid + 1;
      else if(nums[right] > nums[mid])
        if(target > nums[mid] and nums[right] >= target)
          left = mid + 1;
        else
          right = mid - 1;
      else {
        if(nums[left] == nums[mid])
          ++left;

        if(nums[right] == nums[mid])
          --right;
      }
      
    }

    return false;
  }
};



// The version 1 to return the index of target elem

class Solution {
public:
  int search(vector<int>& nums, int target) {
    int left = 0; int right = nums.size()-1;
    while(left <= right) {
      int mid = left + (right-left)/2;
      
      if(target == nums[mid]) 
        return mid;
      
      // array rotated, and 
      if(nums[mid] >= nums[left]) {
        if(target < nums[mid] and target >= nums[left])
          right = mid - 1;
        else 
          left = mid + 1;
      }
      else {
        if(target > nums[mid] and target <= nums[right])
          left = mid + 1;
        else 
          right = mid - 1;
      }
      // right half is sorted
    }
    
    return -1;
  }
};

