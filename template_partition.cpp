// This partition is [left, right]
// It returns the exact pivot index.
int partition(vector<int>& nums, int left, int right) {
  
  int pivot = nums[left], l = left + 1, r = right;
  
  while (l <= r) {
    if (nums[l] < pivot && nums[r] > pivot) {
      // both l and r are opposite, swap them!
      swap(nums[l++], nums[r--]);
    }
    if (nums[l] >= pivot) {
      // l is ok, continue!
      l++;
    }
    if (nums[r] <= pivot) {
      // r is ok, continue!
      r--;
    }
  }
  
  // when while loop exits, r points to 1 element
  // before the l. So even if the array is sorted,
  // r is now the same as left-1, or l-1.
  swap(nums[left], nums[r]);
  // swap(nums[l-1], nums[left]);
  
  // return the exact position of the pivot.
  return r;
}

 
// This is a partition [left, right]
int partition(vector<int>& nums, int left, int right) {

  int pivot = arr[left], l = left+1, r = right;
    
  while (l <= r) {

    // equal case needs to be covered
    while(nums[l] <= pivot) l++;
    while(nums[r] > pivot) r--;

    if (l < r) 
      std::swap(nums[l], nums[r]);

    // after this swapping, 
    // goes back to l++ check,
    // it'll always success for at least
    // once, due to above swap
  }

  // when exiting, l points to next
  // position, so needs to subtract 1.
  std::swap(nums[l - 1], nums[left]);

  // return the first element in 2nd part
  return l;
}

// use stl to write the parition!
// Note that:: due to std::partition is using [left, right)
//
//
// Note that the partition is using [left, right)
// and returns the first element of 2nd partion
int parition(vector<int>& nums, int left, int right) {
  auto pivot = nums.front();
  auto mid = std::partition(nums.begin()+left, nums.begin()+right, [pivot](const auto& em){ return em < pivot; });

  return std::distance(nums.begin(), mid);
}




