class Solution {
public:
  vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
    vector<vector<int>> graph(N+1, vector<int>(2,0));
    for(const auto& pair : paths) {
      graph[pair[0]].emplace_back(pair[1]);
      graph[pair[1]].emplace_back(pair[0]);
    }
    
    vector<int> visit(N+1, 0);
    
    std::function<bool(int, int)> doDFS;
    doDFS = [&graph, &visit, &doDFS, N](int idx, int color) {
      
      for(const auto& outNode : graph[idx])
        if(visit[outNode] == color) return false;
      
      visit[idx] = color;
      
      for(const auto& outNode : graph[idx]) {
        if(visit[outNode]) continue;
        
        for(int i=1; i<=4; ++i) {
          if(i == color) continue;
          visit[outNode] = i;
          if(doDFS(outNode, i)) break;
          visit[outNode] = 0;
        }
      }
      
      return true;
    };
    
    for(int i=1; i<=N; ++i) {
      if(visit[i]==0)
        doDFS(i, 1);
    }
    
    return vector<int>(visit.begin()+1, visit.end());
  }
};
