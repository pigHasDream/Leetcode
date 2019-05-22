class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    int left = 0, right = nums.size()-1;
    while(true) {
      int idx = partition(nums, left, right);
      
      if(idx == k-1) return nums[idx];
      else if(idx > k-1) right = idx-1;
      else if(idx < k-1) left = idx+1;
    }
    
    return -1;
  }
  
  int partition(vector<int>& nums, int left, int right) {
    // this is going to sort in descending order
    int pivot = nums[left];
    int l = left+1, r = right;
    
    while(l <= r) {
      if(nums[l] < pivot and pivot < nums[r]) 
        swap(nums[l++],nums[r--]);
      else if(nums[l] >= pivot) 
        ++l;
      else if(nums[r] <= pivot) 
        --r;
    }
    
    swap(nums[left], nums[r]);
    
    return r;
  }
};
