class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    stack<int> stc;
    vector<int> res(nums.size(), -1);
    
    for(int i=0; i<nums.size()*2; ++i) {
      int j=i%nums.size();
      
      while(stc.size() and nums[stc.top()] < nums[j]) {
        res[stc.top()] = nums[j];
        stc.pop();
      }
      stc.push(j);
    }
    
    return res;
  }
};
