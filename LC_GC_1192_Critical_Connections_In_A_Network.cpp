class Solution {
public:
  vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> graph(n);
    
    for(const auto& edge : connections) {
      graph[edge.front()].emplace_back(edge.back());
      graph[edge.back()].emplace_back(edge.front());
    }
    
    vector<int> low(n, -1);
    vector<int> ids(n, -1);
    // This visit vector can be saved and reused by checking the ids or low
    vector<int> visit(n, 0);
    int globalIdx = 0;
    
    vector<vector<int>> res;
    
    function<void(int,int)> doDFS = [&] (int node, int parent) {
      if(visit[node]) return;
      visit[node] = 1;
      
      low[node] = ids[node] = globalIdx++;
      
      for(const auto& nxt : graph[node]) {
        if(nxt == parent) continue;
        if(not visit[nxt]) {
          doDFS(nxt, node);
          low[node] = min(low[node], low[nxt]);
          if(ids[node]<low[nxt]) {
            res.push_back({node, nxt});
          }
        }
        else {
          low[node] = min(low[node], ids[nxt]);
        }
      }
    };
    
    doDFS(0, -1);
    
    return res;
  }
};
