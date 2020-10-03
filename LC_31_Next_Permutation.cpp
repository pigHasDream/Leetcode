class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    auto iter = is_sorted_until(nums.rbegin(), nums.rend());
    
    if(iter != nums.rend())
      iter_swap(iter, upper_bound(nums.rbegin(), iter, *iter));
    
    reverse(nums.rbegin(), iter);

  }
  
  /*
  void nextPermutation(vector<int>& nums) {
    next_permutation(nums.begin(), nums.end());
  }
  */
};


class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    // 1. from right to left, find the mono increasing range
    //    The pivot elem breaks the mono trending
    auto iter = is_sorted_until(nums.rbegin(), nums.rend());
    // 2. as long as it's not the end, we swap the pivot with
    //    The one first bigger than pivot number
    if(iter != nums.rend()) {
      iter_swap(iter, upper_bound(nums.rbegin(), iter, *iter));
    }

    // 3. finally reverse the part that being checked/changed.
    reverse(nums.rbegin(), iter);
  }
};
