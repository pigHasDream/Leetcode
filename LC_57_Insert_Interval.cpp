class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    if(intervals.empty()) return {newInterval};
    
    vector<vector<int>> res;
    int idx=0;
    while(idx <intervals.size() and intervals[idx].back() < newInterval.front()) {
      res.emplace_back(intervals[idx]);
      ++idx;
    }
    
    int start = newInterval.front(), end = newInterval.back();
    while(idx < intervals.size() and intervals[idx].front() <= newInterval.back()) {
      start = min(intervals[idx].front(), start);
      end = max(intervals[idx].back(), end);
      ++idx;
    }
    
    res.emplace_back(vector<int>({start, end}));
    
    while(idx < intervals.size()) {
      res.emplace_back(intervals[idx]);
      ++idx;
    }
    
    return res;
  }
};
