class Solution {
public:
  double findMaxAverage(vector<int>& nums, int k) {
    double left = -10001;
    double right = 10001;
    
    while(left+1e-5 < right) {
      double mid = left + (right-left)/2;
      if(check(nums, k, mid)) {
        left = mid;
      }
      else {
        right = mid;
      }
    }
    
    return left;
  }
  
  double check(vector<int>& nums, int k, double mid) {
    
    // This is to find
    // if there exists a subarray with at least K length with elements nums[i]-mid
    // such that the sum of them is >= 0.
    double sum = 0;
    double prev = 0;
    double minSum = 0;
    
    // if the first k already meets
    for(int i=0; i<k; ++i) 
      sum += nums[i] - mid;
    
    if(sum >=0) return true;
    
    // if first k not meets,
    // we use 2 running prefix sums,
    // the slow one we keeps getting the min value of them,
    // so that when we do the subtraction, we ensure
    // if there is a >= 0, it's always true!
    for(int i=k; i<nums.size(); ++i) {
      sum += nums[i] - mid; 
      prev += nums[i-k] - mid;
      minSum = min(prev, minSum);
      if(sum - minSum >=0) return true;
    }
    
    return false;
  }
};
