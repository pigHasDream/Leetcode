class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res(intervals);
    
    auto [start, stop] = equal_range(res.begin(), res.end(), newInterval, [](const auto& a, const auto& b){
      return a.back() < b.front(); 
    });
    
    if(start == stop) {
      res.insert(start, newInterval);
    }
    else {
      --stop;
      stop->front() = min(start->front(), newInterval.front());
      stop->back() = max(stop->back(), newInterval.back());
      res.erase(start, stop);
    }

    return res;
  }
};



// Below is a more natural way of thinking.

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    
    vector<vector<int>> res;
    int idx = 0;
    int sz = intervals.size();
    if(sz == 0) return {newInterval};
    
    // anything before the the newInterval without any intersection.
    // Just push into the res
    while(idx < sz and intervals[idx].back() < newInterval.front()) {
      res.emplace_back(intervals[idx++]);
    }
    
    // here we do have intersections, among all of them, choose the min of front, and 
    // max of back as the newInterval
    while(idx < sz  and intervals[idx].front() <= newInterval.back()) {
      newInterval.front() = min(newInterval.front(), intervals[idx].front());
      newInterval.back() = max(newInterval.back(), intervals[idx].back());
      ++idx;
    }
    // push the new interval into the res
    res.emplace_back(newInterval);

    // the right part of the intervals just push into the res blindly
    while(idx < sz) {
      res.emplace_back(intervals[idx++]);
    }
    
    return res;
  }
};
