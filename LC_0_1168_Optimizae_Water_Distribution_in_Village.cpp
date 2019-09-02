class Solution {
public:
  int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
    
    vector<vector<int>> edges(pipes);
    edges.reserve(edges.size()+wells.size());
    
    // The trick is to have a hidden well and the pipe to connect all houses to 
    // this hidden well is wells[i]. Then the problem converts to standard MST
    for(int i=0; i<wells.size(); ++i) {
      edges.emplace_back(vector<int>({0, i+1, wells[i]})); 
    }

    // sort ascending order of edge costs
    sort(edges.begin(), edges.end(), [](const auto& a, const auto& b) {
      if(a[2] == b[2]) {
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
      }
      return a[2] < b[2];
    });
    
    // use Union-Find to init all nodes' parents
    vector<int> parent(n+1);
    iota(parent.begin(), parent.end(), 0);
    
    function<int(int)> find = [&](int idx) {
      if(parent[idx] != idx) {
        parent[idx] = find(parent[idx]);
      }
      return parent[idx];
    };
    
    int res = 0;
    
    // greedily accumulate the smallest edge cost first
    // if 2 nodes of the edge ends are already joined in UF, we skip it.
    // otherwise, we union it!
    for(const auto& e : edges) {
      int p1 = find(e[0]);
      int p2 = find(e[1]);
      
      if(p1 == p2) continue;
        
      parent[p1] = p2;
      
      res += e[2];
    }
    
    return res;
  }
};
