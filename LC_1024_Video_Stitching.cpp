class Solution {
public:
  int videoStitching(vector<vector<int>>& clips, int T) {
    sort(clips.begin(), clips.end(), [](const auto &a, const auto &b){
                                        if(a[0] == b[0]) return a[1] > b[1];
                                        else return a[0] < b[0];});
    
    // 1st greedy: sort clips by start, if tie, largest end comes first
    // 2nd greedy: like jump game II, for each clip, so long as the start
    // is smaller than cur, we take the longest ending.
    int res = 0;
    for(int i=0, cur=0, end=0; cur<T; cur=end, ++res) {
      for(; i<clips.size() and clips[i][0]<=cur; ++i) {
        end = max(end, clips[i][1]);
      }
      if(cur==end) return -1;
    }
    
    return res;
  }
};
