class Solution {
public:
  int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
    
    auto dist = [](const vector<int>& w, const vector<int>& b) {
      return abs(w[0]-b[0]) + abs(w[1]-b[1]);
    };
    
    unordered_map<int,int> memo;
    // doDFS returns the min cost solution!
    // state: the currently already assgined bikes
    // wIdx: the worker id to be assigned with a bike!
    // memo: the min cost value under current bike assignment conditions,
    //       because the worker is always same as the bike counts, only state 
    //       is sufficient to mark the uniqueness.
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




class Solution {
public:
  int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
    
    auto dist = [](const vector<int>& w, const vector<int>& b) {
      return abs(w[0]-b[0]) + abs(w[1]-b[1]);
    };
    
    // The best understanding of this problem can be in 2 ways:
    // 1. Augmented graph to find shortest path: each node is a state, each edge is the cost 
    //    to transit from one state to another state.
    //    Final state is the one we need to arrive at, but we need to get the shortest cost.
    //    Each state to next state only one more bike is assigned!
    //    This is similar to Dijkstra!
    //
    // 2. DFS enumerating all potential solutions with memoization mechanism. For each search,
    //    we keep track of the smallest cost increase!
    
    auto cmp = [](const pair<int,int>& a, const pair<int,int>& b) {
      if(a.first == b.first) {
        return a.second > b.second;
      }
      return a.first > b.first;
    };
    
    const int mask = 0x3ff;
    const int offset = 11;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> que(cmp);
    que.push({0,0});
    
    unordered_set<int> visit;
    while(que.size()) {
      auto top = que.top(); que.pop();
      
      auto cost = top.first;
      auto state = top.second;
      
      int bstate = state & mask;
      if(visit.count(bstate)) continue;
      visit.emplace(bstate);
      
      int widx = state >> offset;
      if(widx == workers.size()) return cost;
      
      for(int i=0; i<bikes.size(); ++i) {
        if((bstate >> i) & 1) continue;
        que.push({cost+dist(workers[widx],bikes[i]), ((widx+1) << offset) | bstate | (1<<i) });
      }
    }
    
    return 0;
  }
};

