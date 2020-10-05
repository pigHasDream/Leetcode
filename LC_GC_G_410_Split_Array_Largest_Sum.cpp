class Solution {
public:
  int splitArray(vector<int>& nums, int m) {
    const int sz = nums.size();
    vector<int> sums(sz+1, 0);
    for(int i=1; i<=sz; ++i)
      sums[i] = sums[i-1] + nums[i-1];
    
    int left = *max_element(nums.begin(), nums.end());
    int right = sums.back()+1;
    
    auto isOK = [&](int sumVal) -> bool {
      int fast = 1, slow = 0;
      int group = 1;
      while(group<m) {
        while(fast <= sz and sums[fast]-sums[slow] <= sumVal) {
          ++fast;
        }
        slow = fast-1;
        ++group;
      }
      
      return sums.back() - sums[slow] <= sumVal;
    };
    
    while(left < right) {
      int mid = left + (right-left)/2;
      if(isOK(mid)) {
        right = mid;
      }
      else {
        left = mid+1;
      }
    }
    
    return left;
  }
};
