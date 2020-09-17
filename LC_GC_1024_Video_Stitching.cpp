class Solution {
public:
  int videoStitching(vector<vector<int>>& clips, int T) {
    sort(begin(clips), end(clips), [](const auto& a, const auto& b){
      return a.front() < b.front();
    });
    
    int res = 0, curStop = 0, nxtStop = 0, idx = 0;
  
    // outer loop checks if we hit the T
    while(curStop < T) {
      
      // inner loop updates the nxt stop point
      while (idx < clips.size() and clips[idx].front() <= curStop) {
        nxtStop = max(nxtStop, clips[idx].back());
        ++idx;
      }
      
      // this means there is a gap and skipped above loop, and re-use prev nxtStop
      if(curStop == nxtStop) return -1;
      
      // Here is a new cycle
      ++res;
      curStop = nxtStop;
    }
    
    return res;
  }
};


// DP solution:
// dp[i] is at i-th position, what is the min number of clips

class Solution {
public:
  int videoStitching(vector<vector<int>>& clips, int T) {
    
    const int sz = clips.size();
    const int inf = 1e6;
    vector<int> dp(T+1, inf);
    dp[0] = 0;
    
    for(int i=1; i<=T; ++i) {
      for(int k=0; k<sz; ++k) {
        // KEY transition function here:
        if(clips[k].front() <= i and i <= clips[k].back()) {
          dp[i] = min(dp[i], dp[clips[k].front()] + 1);
        }
      }
      
      if(dp[i] >= inf) return -1;
    }
    
    return dp.back();
  }
};
