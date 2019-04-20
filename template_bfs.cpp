
//----------------------------
//------- typicla BFS --------
void doBFS() {

  queue<Node> que;
  que.emplace(init_Node);

  while(que.size()) {
    for(int i=que.size(); i>0; --i) {
      auto top = que.front(); 
      que.pop();

      // do something based on the 'top'.

      for(const auto& out : top.outNodes){
        // may skip visited nodes (with loop)
        // or update values for visited (no loop)
        que.emplace(out);
      }
    }
  }

}


//----------------------------
//------ In depth BFS --------
// BFS with K layers and edge weights!
// LC 787
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {

  unordered_map<int, vector<pair<int, int>>> graph;

  for(const auto& f : flights) 
    graph[f[0]].emplace_back(f[1], f[2]);
  
  // each node in queue has node index and current best cost
  queue<pair<int,int>> que;

  que.push({src,0});
  int cost = INT_MAX;
  int stop = -1;
  
  while(que.size()) {
    
    // K layers and stop
    if(stop++ > K) break;
    
    for(int i=que.size(); i>0; --i) {
      auto top = que.front();
      que.pop();
      
      // check for destination
      if(top.first == dst)
        cost = min(cost, top.second);
      
      for(const auto& curDest : graph[top.first]) {
        // Out node pruning. 
        // It's funcitonally not necessary but improves runtime
        if(top.second + curDest.second < cost)
          que.push({curDest.first, top.second + curDest.second});
      }
    }
  }
  
  return cost == INT_MAX ? -1 : cost;
}
