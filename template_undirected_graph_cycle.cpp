// undirected graph detect cycle, and if all nodes conneted

bool hasLoopAndConnected(int n, vector<pair<int, int>>& edges) {
  // n nodes, and a set of edges

  vector<vector<int>> neighbors(n);

  // For undirected graph, do bi-directional creation
  for (const auto& e : edges) {
    neighbors[e.first].emplace_back(e.second);
    neighbors[e.second].emplace_back(e.first);
  }

  vector<bool> visited(n, false);

  // detect cycle
  if (hasCycle(neighbors, 0, -1, visited)) 
    return false;

  // detect connectivity
  for (const auto& v : visited) 
    if (not v) return false; 

  return true;
} 

bool hasCycle(const vector<vector<int>>& neighbors, 
              int curNode, 
              int parent, 
              vector<bool>& visited) {

  // if curNode has visited
  if (visited[curNode]) return true;

  visited[curNode] = true;

  // if the next neighbor node (except for parent) is visited, 
  // that means it has cycle.

  for (auto next : neighbors[curNode])
    if (next != parent and hasCycle(neighbors, next, curNode, visited))
      return true;

  return false;
}
