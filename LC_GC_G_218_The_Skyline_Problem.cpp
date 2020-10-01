class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    
    // Decouple the rectangle to be event lines.
    // Then, we just always pick the largest height one
    // and check for the entering or exiting event

    vector<pair<int, int>> points;
    
    // pair< x pos, height pos> 
    // negative height pos means exiting event
    // positive height pos means entering event
    for(const auto& bldg : buildings) {
      points.emplace_back(bldg[0], bldg.back());
      points.emplace_back(bldg[1], -bldg.back());
    }
    // Note that!!
    // when a.first ties, we put the bigger height first!
    // This is together with the -b[2] to make
    // 1) entering first processed
    // 2) tallest first processed
    // These 2 points cover naturally for the corner cases
    // that two blocks with same size back to back (entering first)
    // also, taller one gets processed first.
    sort(points.begin(), points.end(), [](const auto& a, const auto& b){
      if(a.first == b.first) return a.second > b.second;
      return a.first < b.first;
    });
    
    multiset<int, greater<int>> heights;
    auto maxH = [&]() {
      if(heights.size()) {
        return *heights.begin();
      }
      return 0;
    };
    
    vector<vector<int>> res;
    
    for(const auto& point : points) {
      auto [xpos, height] = point;
      
      bool enter = height > 0;
      int absHeight = abs(height);
      
      if(enter > 0) {
        if(absHeight > maxH()) {
          res.emplace_back(vector<int>{xpos, absHeight});
        }
        heights.emplace(absHeight);
      }
      else {
        heights.erase(heights.find(absHeight));
        if(absHeight > maxH()) {
          res.emplace_back(vector<int>{xpos, *heights.begin()});
        }
      }
    }
    
    return res;

  }
};

class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    
    // x location : height, 1: enter, -1: exit
    vector<pair<int, int>> points;
    
    for(const auto& bldg : buildings) {
      points.emplace_back(bldg[0], bldg.back());
      points.emplace_back(bldg[1], -bldg.back());
    }
    sort(points.begin(), points.end(), [](const auto& a, const auto& b){
      if(a.first == b.first) return a.second > b.second;
      return a.first < b.first;
    });
    
    multiset<int, greater<int>> heights;
    // Here we put 0 as an anchor value!
    heights.emplace(0);
    
    vector<vector<int>> res;
    
    for(const auto& point : points) {
      auto [xpos, height] = point;
      
      bool enter = height > 0;
      int absHeight = abs(height);

      // each time a new line of enter comes in, we push it
      // each time a new line of exit comes in, we delete it
      
      if(enter > 0) {
        // If the new one is higher than the BST top, we have an ascending
        if(absHeight > *heights.begin()) {
          // here we push the new height
          res.emplace_back(vector<int>{xpos, absHeight});
        }
        heights.emplace(absHeight);
      }
      else {
        heights.erase(heights.find(absHeight));
        // If the deleted one is higher than the BST top, we have a descending
        if(absHeight > *heights.begin()) {
          // here we push the heights.begin()
          res.emplace_back(vector<int>{xpos, *heights.begin()});
        }
      }
    }
    
    return res;

  }
};
