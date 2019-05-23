class Solution {
public:
  int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    
    int left=0, right=nums.back()+1;
    
    // we are looking for the mid value (the k-th smallest dist)
    // such that there are k numbers of such pairs no greater than
    // this mid!
    while(left < right) {
      int mid = left + (right-left)/2;
      
      int count = 0;
      // this for-loop is to get the count of pairs that have
      // distance smaller or equal to mid
      // Here we use a sliding window (2 pointer) to do that in
      // a linear time!
      for(int start=0, end=0; start<nums.size(); ++start) {
        while(end<nums.size() and nums[end]-nums[start]<=mid) ++end;
        count += end-start-1;
      }
      
      if(count>=k) 
        right = mid;
      else 
        left = mid+1;
    }

    return left;
  }
};
