vector<int> dijkstra(const vector<vector<pair<int, int>>>& graph, int N, int K) {
  // graph data structure: curNode is implict in index, the pair is {outNode, cost}
  // vector<vector<pair<int, int>>>& graph

  // This returns the shortest path from node K (index K-1) to all other nodes
  vector<int> cost(N, INT_MAX);

  // priority_queue also sorts by first member of the pair
  // {pair, outNode}
  priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> theQueue;

  theQueue.push({0, K-1});

  while(theQueue.size()) {
    int curCost = theQueue.top().first;
    int nodeIdx = theQueue.top().second;
    theQueue.pop();

    if(cost[nodeIdx] != INT_MAX)
      continue;

    cost[nodeIdx] = curCost;
    
    for(auto neighbor : graph[nodeIdx]) {
      theQueue.push({neighbor.second + curCost, neighbor.first});
    }
  }

  return cost;
}
