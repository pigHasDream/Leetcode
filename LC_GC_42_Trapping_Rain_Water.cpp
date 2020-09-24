/* 1. soluiton with 2 pointers:
 * Idea is to count per bin => **vertically** accumulate the area. 
 * The current bin's value is depending on the left side's max and right side's max whichever is shorter.
 * The idea is to keep track of left side and right side tall bar. Update them accordingly.
 *
 * 
 * 2. stack solution:
 * Idea is to solve **horizontally** per level.
 * keep stack as a monotonic decrasing order, and pop up one by one as long as the incoming bar is larger than the stack top!
 * The area is calculated horizontally and level-by-level.  */


// ------------------------------------------------
class Solution {
public:
  int trap(vector<int>& height) {
    int left = 0, right = height.size()-1;
    int maxLevel = 0;
    
    int res = 0;
    
    while(left < right) {
      if(height[left] < height[right]) {
        height[left] >= maxLevel
          ? (maxLevel = height[left])
          : res += maxLevel - height[left];
        ++left; 
      }
      else {
        height[right] >= maxLevel 
          ? (maxLevel = height[right])
          : res += maxLevel - height[right];
        --right; 
      }
    }
    
    return res;
  }
};

// ------------------------------------------------
class Solution {
public:
  int trap(vector<int>& height) {
    vector<int> nums(height);
    nums.emplace_back(0);
    
    stack<int> stc;
    int res = 0;
    for(int i=0; i<nums.size(); ++i) {
      while(stc.size() and nums[stc.top()] < nums[i]) {
        auto top = stc.top();
        stc.pop();
        
        int wid = i - (stc.empty() ? -1 : stc.top()) - 1;
        int hi = stc.empty() ? 0 : (min(nums[i], nums[stc.top()]) - nums[top]);
        res += wid*hi;
      }
      stc.emplace(i);
    }
    
    return res;

  }
};



