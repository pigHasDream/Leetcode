class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    
    sort(nums.begin(), nums.end());
    
    vector<vector<int>> res;
    
    for(int i=0; i<nums.size();) {
      for(int j=i+1; j<nums.size();) {
        int sum = target - nums[i] - nums[j];
        
        int left = j+1, right = nums.size()-1;
        while(left < right) {
          if(nums[left] + nums[right] > sum) --right;
          else if(nums[left] + nums[right] < sum) ++left;
          else {
            res.emplace_back(vector<int>({nums[i], nums[j], nums[left], nums[right]}));
            ++left;
            --right;
            while(left<right and nums[left-1] == nums[left]) ++left;
            while(left<right and nums[right+1] == nums[right]) --right;
          }
        }
        
        ++j;
        while(j<nums.size() and nums[j-1] == nums[j]) ++j;
      }
      ++i;
      while(i<nums.size() and nums[i-1] == nums[i]) ++i;
    }
    
    return res;
  }
};
