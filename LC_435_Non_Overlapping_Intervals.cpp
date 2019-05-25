class Solution {
public:
  // This is a classic interval scheduling problem.
  // We use greedy algorithm sorted by end
  // remove all conflicts to this end, and iterate through
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {return a[1] < b[1];}); 
    int res = 0;
    int prev = -1;
    for(const auto& in : intervals) {
      if(prev == -1 or in[0] >= prev) prev = in[1];
      else ++res;
    }
    
    return res;
  }
};
