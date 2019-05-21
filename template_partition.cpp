int partition(vector<int>& nums, int left, int right) {
  
  int pivot = nums[left], l = left + 1, r = right;
  
  while (l <= r) {
    if (nums[l] < pivot && nums[r] > pivot) {
      swap(nums[l++], nums[r--]);
    }
    if (nums[l] >= pivot) {
      l++;
    }
    if (nums[r] <= pivot) {
      r--;
    }
  }
  
  swap(nums[left], nums[r]);
  
  return r;
}
