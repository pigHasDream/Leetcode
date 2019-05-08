class Solution {
public:
  vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<string> res;
    // lower can be out of bounds of the nums array
    long lo = lower;
    // upper can also be out of bounds of the nums array
    long up = upper;
    
    for(int i=0; i<nums.size(); ++i) {
      if(lo < (long)nums[i]-1) 
        res.emplace_back(to_string(lo) + "->" + to_string(nums[i]-1));
      else if (lo == (long)nums[i]-1)
        res.emplace_back(to_string(lo));
      
      lo = (long)nums[i]+1;
    }
    
    if(lo < up) 
      res.emplace_back(to_string(lo) + "->" + to_string(up));
    else if(lo == up)  
      res.emplace_back(to_string(lo));
    
    return res;
  }
  
};
//////////////////////////////////////////////////////////////////////////




class Solution {
public:
  vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    vector<string> res;

    // Using binary search to find the start index in nums
    long left = lower;
    long right = -1;
    
    for (int i = lower_bound(nums.begin(), nums.end(), lower) - nums.begin(); left <= upper; ++i ) {
      
      // [left, right] is the current missing range
      right = i < nums.size() ? min(long(upper), long(nums[i]) - 1) : upper;  
      
      if (left <= right) 
        res.emplace_back(to_string(left) + (left == right ? "" : "->" + to_string(right))); 
      
      left = right + 2;
    }
    
    return res;
  }
};
