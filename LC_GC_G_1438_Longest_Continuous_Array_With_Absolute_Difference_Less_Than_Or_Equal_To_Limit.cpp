class Solution {
public:
  int longestSubarray(vector<int>& nums, int limit) {
    
    multiset<int> bst;
    int res = 0;
    int left = 0;
    
    for(int right=0; right<nums.size(); ++right) {
      bst.emplace(nums[right]);
      while(bst.size() and *bst.rbegin()-*bst.begin()>limit) {
        bst.erase(bst.find(nums[left++]));
      }
      
      res = max(res, int(bst.size()));
    }

    return res;
  }
};


class Solution {
public:
  int longestSubarray(vector<int>& nums, int limit) {
    deque<int> maxQue;
    deque<int> minQue;
    int sz = nums.size();
    int res = 0;
    int left = 0, right = 0;
    
    while(right < sz) {
      while(maxQue.size() and nums[maxQue.back()] < nums[right]) {
        maxQue.pop_back();
      }
      
      while(minQue.size() and nums[minQue.back()] > nums[right]) {
        minQue.pop_back();
      }
      
      maxQue.emplace_back(right);
      minQue.emplace_back(right);
      
      // as long as there is one elem in que, 
      // the > sign won't be valid in current problem setup
      while(nums[maxQue.front()] - nums[minQue.front()] > limit) {
        
        if(nums[maxQue.front()] == nums[left]) maxQue.pop_front();
        if(nums[minQue.front()] == nums[left]) minQue.pop_front();
        
        ++left;
      }
      
      res = max(res, right-left+1);
      ++right;
    }
    
    return res;
  }
};
