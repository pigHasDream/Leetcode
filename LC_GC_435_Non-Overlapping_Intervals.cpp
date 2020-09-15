// We can actually sort based on either start or end!!
//
// Sort by start:
// We traverse through the list, key is to update the "last" pointer based on greedy manner:
// if the current end is shorter than last end, we update the last to current, 
// bacause it'll have less chance to overlap with upcoming elements. Otherwise we keep the last pointer unchanged!
//
// Sort by end:
// We traverse through the list, key is this traversal implicitly keep the first end segment 
// prioritized and checked first. 
// So any upcoming overlap discovered, we always kicks the new one, and keep the last pointer.


// ---------------------------------------------------------------------------------
// Sort by end!
class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    
    sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
      if(a.back() == b.back()) 
        return a.front() < b.front();
      return a.back() < b.back();
    });
    
    int res = 0;
    int last = 0;
    
    for(int i=1; i<intervals.size(); ++i) {
      if(intervals[i].front() < intervals[last].back()) {
			// any overlap detected, we implicitly kicks the later one!!
			// do not update the last pointer!
        ++res;
      }
      else {
        last = i; 
      }
    }
    
    return res;

  }
};

// ---------------------------------------------------------------------------------
// Sort by start!
class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    
    sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
      if(a.front() == b.front()) 
        return a.back() < b.back();
      return a.front() < b.front();
    });
    
    int res = 0;
    int last = 0;
    for(int i=1; i<intervals.size(); ++i) {
      if(intervals[i].front() < intervals[last].back()) {
        ++res;
        // Sort by start, we'll also need to select whether the last one or new one
        // to get kicked out. Based on end point check. We'd like to keep shorter one!
        if(intervals[i].back() < intervals[last].back())
          last = i;
      }
      else {
        last = i; 
      }
    }
    
    return res;

  }
};



// -----------------------------------------------------------------------------------
// Sort by end and use total size to subtract the max schedule result!
class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    // max scheduling: find the max number of non conflict!
    // use total num to subtract the non-overlap ones
      
    sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
      if(a.back() == b.back()) 
        return a.front() < b.front();
      return a.back() < b.back();
    });
    
    int maxNum = 0;
    int prev = INT_MIN;
    for(const auto& intv : intervals) {
      if(prev <= intv.front()) {
        ++maxNum;
        prev = intv.back(); 
      }
    }
    
    return intervals.size() - maxNum;
  }
};
