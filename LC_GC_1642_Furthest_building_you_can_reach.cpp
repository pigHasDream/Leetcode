class Solution {
public:
  int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    // binary search can do, but likely ends up with O(log(n)*n*log(n))
    
    priority_queue<int> que;
    for(int i=1; i<heights.size(); ++i) {
      int diff = heights[i] - heights[i-1];
      if(diff > 0) {
        que.emplace(diff);
        bricks -= diff; 
        if(bricks < 0) {
          bricks += que.top();
          que.pop();
          if(ladders <= 0) return i-1;
          --ladders;
        }
      }
    }

    return heights.size()-1;
  }
};
