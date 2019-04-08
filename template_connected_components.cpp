class Solution { 
public:
  
  int numComponents() {
    // count connected componets of graph
    unordered_map<int, vector<int>> graph;
    int ans = 0;

    unordered_set<int> visited;

    for (const auto& u : graph) {      
      if (visited.count(u)) continue;
      ++ans;
      // DFS to mark visited.
      dfs(u, graph, visited);
    }
    
    return ans;
  }

  void dfs(const int cur, 
           const unordered_map<int, vector<int>>& graph, 
           unordered_set<int>& visited) {
    
    if (visited.count(cur)) return;
    
    visited.insert(cur);
    
    for (const auto& next : graph[cur])
      dfs(next, graph, visited);  
    
  }
};
