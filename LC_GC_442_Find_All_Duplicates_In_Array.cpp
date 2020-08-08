class Solution {
public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> res; 
    
    // key observations
    // 1. all elem has value -1 becomes a valid index of the array
    // 2. each time we flip negative of that nums[idx], indicating "visited"
    // 3. when encountered again (the 2nd time), we know it's visited again.
    for(int i=0; i<nums.size(); ++i) {
      if(nums[abs(nums[i])-1] < 0)
        res.emplace_back(abs(nums[i]));
      else
        nums[abs(nums[i]) -1] *= -1;
    }

    // revert all values
    for(auto& n : nums)
      n = abs(n);
    
    return res;
  }
};
