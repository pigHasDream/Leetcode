class Solution {
public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) { return a[0] < b[0];});
    
    priority_queue<int, vector<int>, greater<int>> que;
    for(const auto& in : intervals) {
      if(not que.empty() and in[0]>=que.top()) que.pop();
      que.push(in[1]);
    }
    
    return que.size();
  }
};



class Solution {
public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    
    vector<int> startVec(intervals.size(), -1);
    vector<int> endVec(intervals.size(), -1);
    for(int i=0; i<intervals.size(); ++i) {
      startVec[i] = intervals[i][0];
      endVec[i] = intervals[i][1];
    }
    
    sort(startVec.begin(), startVec.end());
    sort(endVec.begin(), endVec.end());
    
    int res = 0;
    for(int i=0, endIter=0; i<intervals.size(); ++i) {
      if(startVec[i] < endVec[endIter]) {
        ++res;
      }
      else {
        ++endIter;
      }
    }
    
    return res;
  }
};
