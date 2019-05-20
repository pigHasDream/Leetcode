class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    unordered_map<int, unordered_set<int>> graph;
    for(const auto &e : edges) {
      graph[e[0]].insert(e[1]);
      graph[e[1]].insert(e[0]);
    }
    
    queue<int> que;
    for(int i = 0; i<n; ++i)
      if(graph[i].size() == 1) que.push(i);
    
    while(que.size() and graph.size()>2) {
      for(int i=que.size(); i>0; --i) {
        auto top = que.front(); que.pop();
        
        for(auto& next : graph[top]) {
          graph[next].erase(top);
          if(graph[next].size() == 1)
            que.push(next);
        }
        graph.erase(top);
      }
    }
    
    vector<int> res;
    for(const auto& node : graph)
      res.emplace_back(node.first);
    
    return res;
  }
};
