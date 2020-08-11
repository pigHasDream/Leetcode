
// MST is defined in undirected graph.
// UnionFind on undirected graph is sufficient
// to tell a loop if both nodes are union already.

// This API returns mst's edge sum
int doKruskalMST() { 

  // edge cost first, then two nodes
  // {cost, {u, v}}
  vector<pair<int, pair<int, int>>> edges;
  int res = 0;
  
  // sort ascending based on first in pair
  // This is the key!
  sort(edges.begin(), edges.end()); 
  
  // union find to check circle
  UnionFind theUF(n);
  
  for (const auto& edge : edges) { 
    auto u = edge.second.first;
    auto v = edge.second.second;

    int pU = theUF.Find(u);
    int pV = theUF.Find(v);

    // if no circle, add new edge
    // i.e. two nodes to union.
    if (pU != pV) { 
      res += edge.first;
      theUF.union(u, v); 
    } 
  } 
  
  return res;

} 


// LC 1135 example

class Solution {
public:
  int minimumCost(int N, vector<vector<int>>& connections) {
    vector<int> parent(N+1, 0);
    iota(parent.begin(), parent.end(), 0);
    
    sort(connections.begin(), connections.end(), [](const auto& a, const auto& b) {
      if(a[2] == b[2]) {
        if(a[0] == b[0])
          return a[1] < b[1];
        return a[0] < b[0];
      }
      return a[2] < b[2];
    });
    
    function<int(int)> findParent = [&] (int node) {
      if(node == parent[node]) 
        return node;
      
      return parent[node] = findParent(parent[node]);
    };
    
    int res = 0;
    
    for(const auto& e : connections) {
      int p0 = findParent(e[0]);
      int p1 = findParent(e[1]);
      
      if(p0 == p1)
        continue;
      
      res += e.back();
      parent[p0] = p1;
    }
    
    int cnt = 0;
    for(int i=1; i<=N; ++i)
      if(i == parent[i])
        ++cnt;
    
    return cnt > 1 ? -1 : res;
  }
};
