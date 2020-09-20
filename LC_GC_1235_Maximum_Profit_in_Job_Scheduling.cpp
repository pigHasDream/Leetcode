class Solution {
public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    
    int sz = startTime.size();
    vector<vector<int>> event(sz, vector<int>(3,0));
    
    for(int i=0; i<sz; ++i) {
      event[i][0]=startTime[i];
      event[i][1]=endTime[i];
      event[i][2]=profit[i];
    }
    
    // sort by end! so that we can find the 
    sort(event.begin(), event.end(), [](const auto& a, const auto& b){
      return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
    });

    // after considering event[i], what is the best profit?
    vector<int> dp(sz, 0);
    
    for(int i=0; i<sz; ++i) {
      if(i==0) {
        dp[i] = event[i][2];
        continue;
      }
      
      int bestNonOverlapCost = 0;
      for(int j=i-1; j>=0; --j) {
        if(event[j][1]<=event[i][0]) {
          bestNonOverlapCost = dp[j];
          break; 
        }
      }
      
      // here we consider if use or not use i-th event!!
      dp[i] = max(dp[i-1], bestNonOverlapCost+event[i][2]);
    }
    
    return dp.back();
  }
};


class Solution {
public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    
    int sz = startTime.size();
    vector<vector<int>> event(sz, vector<int>(3,0));
    
    for(int i=0; i<sz; ++i) {
      event[i][0]=endTime[i];
      event[i][1]=startTime[i];
      event[i][2]=profit[i];
    }
    
    // sort by end! so that we can find the 
    sort(event.begin(), event.end());

    map<int,int> dp{{0,0}};
    
    for(const auto& e : event) {
      // Here we need to check the upper_bound and call prev to really get the LAST elem
      // that is non-overlap with the new data!!
      // Calling lower_bound may fail for the case of consecutive ending point case!

      int prevCost = prev(dp.upper_bound(e[1]))->second + e[2];
      
      if(dp.rbegin()->second < prevCost) {
        dp[e[0]] = prevCost;
      }

    }
    
    return dp.rbegin()->second;
  }
};




// BELOW solution is NOT passing the Leetcode!
// It however shows how to optimize the inner loop of finding the endpoint without
// overlap with the upcoming value.
class Solution {
public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    
    int sz = startTime.size();
    vector<vector<int>> event(sz, vector<int>(3,0));
    
    for(int i=0; i<sz; ++i) {
      event[i][0]=startTime[i];
      event[i][1]=endTime[i];
      event[i][2]=profit[i];
    }
    
    // sort by end! so that we can find the 
    sort(event.begin(), event.end(), [](const auto& a, const auto& b){
      return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
    });

    // after considering event[i], what is the best profit?
    vector<int> dp(sz, 0);
    
    for(int i=0; i<sz; ++i) {
      if(i==0) {
        dp[i] = event[i][2];
        continue;
      }
      
      int left = 0, right = i;
      while(left < right) {
        int mid = left + (right-left)/2;
        if(event[mid][1] < event[i][0]) {
          left = mid+1;
        }
        else {
          right = mid;
        }
      }
      
      int nonOverlapBestCost = 0;
      if(left > 0)
        nonOverlapBestCost = dp[left];
      
      // here we consider if use or not use i-th event!!
      dp[i] = max(dp[i-1], nonOverlapBestCost+event[i][2]);
    }
    
    return dp.back();
  }
};
