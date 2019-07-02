class Solution {
public:
  // This problem has several things:
  // 1. We can use Union-Find, but this is string, so we need
  // to use map to map string to string.
  // 2. We can also use DFS like this solution, the we need to
  // convert the relation to be a graph.
  // 3. converting set relation to a graph: make each neighboring 
  // element in the same set as an edge, and make the edge dual direction!!
  // 4. collect connected component for the results
  // 5. final result requires the solution to be sorted, so use set!
  vector<vector<string>> accountsMerge(vector<vector<string>>& acts) {
    
    unordered_map<string, set<string>> graph;
    unordered_map<string, string> nameMap;
    unordered_set<string> visit;
    vector<vector<string>> res;
    
    buildGraph(acts, graph, nameMap);
    
    // This is basically the way to return components!
    for(const auto& p : graph) {
      auto node = p.first;
      if(visit.count(node)) continue;
      set<string> curRes;
      doDFS(graph, visit, node, curRes);
      
      vector<string> r(curRes.begin(), curRes.end());
      r.insert(r.begin(), nameMap[node]);
      res.emplace_back(r);
    }
    
    return res;
  }
  
  // build undirected graph
  void buildGraph(vector<vector<string>>& acts, 
                  unordered_map<string, set<string>>& graph,
                  unordered_map<string, string>& nameMap) {
    
    for(int i=0; i<acts.size(); ++i) {
      for(int j=1; j<acts[i].size(); ++j) {
        nameMap[acts[i][j]] = acts[i][0];
        // for solo node, insert a special empty string
        graph[acts[i][1]].insert("");
        
        // Here the adj nodes are inserted with dual directions
        if(j==1) continue;
        graph[acts[i][j]].insert(acts[i][j-1]);
        graph[acts[i][j-1]].insert(acts[i][j]);
      }
    }
  }
  
  // normal DFS. Mark the visit and record curRes for current node
  void doDFS(unordered_map<string, set<string>>& graph,
             unordered_set<string>& visit,
             string node,
             set<string>& curRes) {
    
    if(visit.count(node)) return;
   
    visit.insert(node);
    curRes.insert(node);
    
    for(const auto& next : graph[node]) {
      if(next.empty() or visit.count(next)) continue;
      doDFS(graph, visit, next, curRes);
    }
  }
    
};
