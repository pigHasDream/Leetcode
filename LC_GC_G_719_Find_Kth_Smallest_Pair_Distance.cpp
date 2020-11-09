class Solution {
public:
  int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    
    int left = 0, right = 1000001;
    while(left < right) {
      int mid = left + (right-left)/2;
      
      int count = 0;
      // 2-pointers: every time j exits,
      // we can continue the j, no need to start from 0 for j!!
      for(int i=0, j=0; i<nums.size(); ++i) {
        while(j<nums.size() and nums[j]-nums[i]<=mid) ++j;
        
        count += j-i-1;
      }
      
      // Here we use absolute <
      if(count < k) {
        left = mid+1;  
      }
      // here the answer includes in this range!
      else {
        right = mid;
      }
    }

    return right;
  }
};
