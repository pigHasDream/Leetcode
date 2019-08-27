class Solution {
public:
  int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
    
    auto dist = [](const vector<int>& w, const vector<int>& b) {
      return abs(w[0]-b[0]) + abs(w[1]-b[1]);
    };
    
    unordered_map<int,int> memo;
    
    function<int(int,int)> doDFS = [&](int wIdx, int state) {
      
      if(wIdx >= workers.size()) {
        return 0;
      }
      
      if(memo.count(state))
        return memo[state];
      
      int minCost = INT_MAX;
      for(int i=0; i<bikes.size(); ++i) {
        if((state >> i)&1) continue;
        
        state ^= 1<<i;
        minCost = min(minCost, dist(workers[wIdx], bikes[i]) + doDFS(wIdx+1, state));
        state ^= 1<<i;
      }
      
      return memo[state] = minCost;
    };
    
    return doDFS(0, 0);
    
  }
};
