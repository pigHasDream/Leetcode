class Solution {
public:
  bool canJump(vector<int>& nums) {
    int maxEnd = 0;
    
    // Treat this as a BFS approach
    for(int i=0; i<nums.size(); ++i) {
      if(maxEnd < i) return false;
      maxEnd = max(maxEnd, i+nums[i]);
    }
    
    return true;
  }
};
