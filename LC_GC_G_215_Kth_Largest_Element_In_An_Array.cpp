class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    auto count = [&](long val) {
      int count = 0;
      // Note that we check with n >= val
      for(const auto& n : nums) 
        count += (n>=val);
      return count;
    };
    
    auto [lo, hi] = minmax_element(nums.begin(), nums.end());
    long left = *lo, right = (*hi)+1l;
    
    while(left < right) {
      long mid = left + (right - left)/2;
      
      // here also count >= k
      if(count(mid) >= k) {
        left = mid+1;
      }
      else {
        right = mid;
      }
    }
    
    return left-1;
  }
};
