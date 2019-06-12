class Solution {
public:
  bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int dest) {
    
    vector<vector<int>> graph(n);
    
    for(const auto& e : edges) 
      graph[e[0]].emplace_back(e[1]);
      
    // check loop topological sort
    // -1: unvisit, 0: visiting, 1: visited
    vector<int> status(n, -1);
    
    function<bool(int)> doDFS = [&](int cur) {
      if(graph[cur].empty())
        return cur == dest;
      
      if(status[cur] == 0) 
        return false;
      
      if(status[cur] == 1)
        return true;
      
      status[cur] = 0;
      for(const auto& next : graph[cur]) {
        if(not doDFS(next)) return false;
      }
      
      status[cur] = 1;
      return true;
    };
    
    return doDFS(source);
  }
};
