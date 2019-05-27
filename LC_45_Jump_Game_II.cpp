class Solution {
public:
  int jump(vector<int>& nums) {
    int n=nums.size(), curEnd=0, nextMax=0, step=0;
    
    // BFS based solution. 
    // each time the curEnd means the current layer.
    // when current layer finishs and not yet hit the 
    // destination, we need to increase the step.
    // And extend the next bound.
    for(int i=0; i<n; ++i) {
      // get the next bound!
      nextMax=max(nextMax, i+nums[i]);
      if(i>=n-1) break;
      if(i==curEnd) {
        ++step;
        curEnd = nextMax;
      }
    }
    
    return step;

  }
};
