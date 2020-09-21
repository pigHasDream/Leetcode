class Solution {
public:
  // Bellman Ford algorithm can directly work on the edge based inputs!
  // This is like the Kruskal's algo where we just do UnionFind on edges!
  int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    vector<vector<int>> graph(N+1);
    
    const int inf = INT_MAX/2;
    vector<int> dist(N+1, inf);
    dist[0] = 0; // this is a dummy element to make loop easier.
    dist[K] = 0; // this is the starting source, has 0 dist
    
    // loop over vertex-1 times, Note that the outer loop is |V|-1
    for(int i=1; i<N; ++i) {
      for(const auto& edge : times) {
        int fromNode = edge[0];
        int toNode = edge[1];
        int cost = edge[2];
        
        dist[toNode] = min(dist[toNode], dist[fromNode]+cost);
      }
    }
      
    // Need one more loop to detect negative loop.
    for(const auto& edge : times) {
      int fromNode = edge[0];
      int toNode = edge[1];
      int cost = edge[2];

      // detect negative loop
      if(dist[fromNode]+cost < dist[toNode])
        return -1;
    }
    
    int res = *max_element(dist.begin(), dist.end());
    
    return res == inf ? -1 : res;
  }
};
