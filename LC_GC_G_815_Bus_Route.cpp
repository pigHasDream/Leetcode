class Solution {
public:
  int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
    
    unordered_map<int, unordered_set<int>> stop2Bus;
    for(int i=0; i<routes.size(); ++i) {
      for(const auto& stop : routes[i]) {
        stop2Bus[stop].emplace(i);
      }
    }

    // Key here is the 2 visit check to avoid duplication!
    unordered_set<int> visitStop;
    unordered_set<int> visitBus;
    int res = -1;
    
    // each elem is one stop
    queue<int> que;
    que.emplace(S);
    visitStop.emplace(S);
   
    while(que.size()) {
      ++res;
      
      for(int k=que.size(); k>0; --k) {
        auto stop = que.front();
        que.pop();
        
        if(stop == T) 
          return res;
        
        for(const auto& bus : stop2Bus[stop]) {
          if(visitBus.count(bus)) continue;
          visitBus.emplace(bus);
          for(const auto& nxtStop : routes[bus]) {
            if(visitStop.count(nxtStop)) continue;
            que.emplace(nxtStop);
            visitStop.emplace(nxtStop);
          }
        }
      }
    }
    
    return -1;
  }
};
