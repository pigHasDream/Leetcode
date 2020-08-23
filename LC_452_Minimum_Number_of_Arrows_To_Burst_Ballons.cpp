class Solution {
public:
  int findMinArrowShots(vector<vector<int>>& points) {
    if(points.empty()) return 0;
    // This one is to use greedy.
    // for each ballon, the max range it covers is the value
    
    sort(points.begin(), points.end(), [](const auto &a, const auto &b) {return a[1] < b[1];});

    int res=1;
    int prevEnd=points[0].back();

    for(int i=1; i<points.size(); ++i) {
      // NOTE: we have to use strict < here.
      // because == can also lead to overlap hence save one shot
      if(prevEnd < points[i].front()) {
        ++res;
        prevEnd = points[i].back();
      }
    }

    return res;
  }
};
