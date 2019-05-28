class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    // Decouple the rectangle to be event lines.
    // Then, we just always pick the largest height one
    // and check for the entering or exiting event
    
    multiset<int> bst;
    // pair< x pos, height pos> 
    // negative height pos means exiting event
    // positive height pos means entering event
    vector<pair<int,int>> events;
    
    for(const auto& b : buildings) {
      events.emplace_back(b[0], b[2]);
      events.emplace_back(b[1], -b[2]); 
    }
    
    sort(events.begin(), events.end(), [](const auto &a, const auto &b) {
      if(a.first == b.first) return a.second > b.second;
      return a.first < b.first;
    });
    
    auto maxH = [&bst]() -> int {
      if(bst.empty()) return 0;
      return *bst.rbegin(); 
    };
    
    vector<vector<int>> res;
    for(const auto &e : events) {
      bool enter = e.second > 0;
      int height = abs(e.second);
      int x = e.first;
      
      if(enter) {
        if(height > maxH()) {
          vector<int> curPoint = {x, height};
          res.emplace_back(curPoint);
        }
        bst.insert(height);
      }
      else{
        bst.erase(bst.equal_range(height).first);
        if(height > maxH()) {
          vector<int> curPoint = {x, maxH()};
          res.emplace_back(curPoint);
        }
      }
    }
    
    return res;
  }
};
