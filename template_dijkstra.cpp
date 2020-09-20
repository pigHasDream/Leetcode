// Below is the network time problem!!
// Notice the if- comparison done inside the for-loop
// This is a directed graph

class Solution {
public:
  int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    
    vector<vector<pair<int,int>>> graph(N+1);
    
    for(const auto& e : times) {
      graph[e[0]].emplace_back(e[2], e[1]);
    }
    
    auto cmp = [](const auto& a, const auto& b) {
      if(a.first == b.first) return a.second < b.second;
      return a.first < b.first;
    };
    
    const int inf = INT_MAX/2;
    vector<int> res(N+1, inf);
    
    // pair : {cost, outNode}
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> que(cmp);
    que.emplace(0, K);
    res[K] = 0;
    
    while(que.size()) {
      auto top = que.top();
      que.pop();
      
      auto soFarCost = top.first;
      auto curNode = top.second;
      
      for(const auto& nxt : graph[curNode]) {
        auto edgeCost = nxt.first; 
        auto nxtNode = nxt.second;
        
        if(soFarCost + edgeCost < res[nxtNode]) {
          res[nxtNode] = soFarCost + edgeCost;
          que.emplace(res[nxtNode], nxtNode);
        }
        
      }
    }

    int ret = *max_element(next(res.begin()), res.end());
    return ret == inf ? -1 : ret;
    
  }
};
