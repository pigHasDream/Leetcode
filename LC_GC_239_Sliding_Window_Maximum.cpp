ass Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    
    vector<int> res;
    deque<int> que;
    
    for(int i=0; i<nums.size(); ++i) {
      while(que.size() and nums[que.back()] < nums[i]) {
        que.pop_back(); 
      }
      que.emplace_back(i);
    
      if(i<k-1) continue;

      if(que.front() <= i-k) {
        que.pop_front();
      }
      
      res.emplace_back(nums[que.front()]);
    }

    return res;
  }
};
