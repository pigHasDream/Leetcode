class Solution {
public:
  int splitArray(vector<int>& nums, int m) {
    if(nums.size() == 1) return nums[0];
    
    vector<long> prefixSum(nums.size()+1, 0);
    for(int i=1; i<prefixSum.size(); ++i) {
      prefixSum[i] = prefixSum[i-1] + nums[i-1];
    }
    
    long left=0, right=prefixSum.back();
    while(left < right) {
      long mid = left + (right-left)/2;
      if(checkTheSplit(prefixSum, m-1, mid) >= 0) 
        right = mid;
      else 
        left = mid+1;
    }

    return left;
  }
  
private:
  int checkTheSplit(const vector<long>& prefixSum, 
                    int m,
                    const long mid) {
    
    // greedily insert the separator to check
    int idx=1, prevIdx=0;
    while(idx<prefixSum.size()) {
      if(prefixSum[idx] - prefixSum[prevIdx] <= mid) {
        ++idx;
      }
      else {
        prevIdx = idx-1;
        --m;
      }
      if(m<0) break;
    }
     
    return m;
  }
};
