class Solution {
public:
  int numComponents() {
    unordered_map<int, vector<int>> g;
    int ans = 0;

    unordered_set<int> visited;

    for (int u : G) {      
      if (visited.count(u)) continue;
      ++ans;
      dfs(u, g, visited);
    }
    return ans;
  }
private:

  void dfs(int cur, unordered_map<int, vector<int>>& g, unordered_set<int>& visited) {
    if (visited.count(cur)) return;
    visited.insert(cur);
    for (const int next : g[cur])
      dfs(next, g, visited);    
  }
};
