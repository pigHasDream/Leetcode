class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if(intervals.empty()) return {};
    
    sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {return a[0] < b[0];});
    
    vector<vector<int>> res;
    res.emplace_back(intervals.front());
    
    for(int i=1; i<intervals.size(); ++i) {
      if(res.back().back() < intervals[i].front()) {
        res.emplace_back(intervals[i]);
      }
      else {
        res.back().back() = max(res.back().back(), intervals[i].back());
      }
    }
    return res;
  }
};
