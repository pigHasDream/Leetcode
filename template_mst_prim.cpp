vector<int> prim(const vector<vector<pair<int, int>>>& graph) {
  // graph data structure: curNode is implict in index, the pair is {outNode, cost}
  // vector<vector<pair<int, int>>>& graph

  // Initialize each node cost to inf
  // also serve as the visit check vector
  vector<int> visit(N, 0);

  // priority_queue also sorts by first member of the pair
  // {pair, outNode}
  priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> theQueue;

  // start with arbitraty node index, here from 0
  theQueue.push({0, 0});

  while(theQueue.size()) {
    int edgeCost = theQueue.top().first;
    int nodeIdx = theQueue.top().second;
    theQueue.pop();

    if(visit[nodeIdx])
      continue;

    visit[nodeIdx] = 1;
    
    for(auto neighbor : graph[nodeIdx]) {
      theQueue.push({neighbor.second, neighbor.first});
    }
  }

  vector<int> res;
  std::copy(visit.begin(), visit.end(), std::back_inserter(res), [](const auto& a) { return a > 0; });

  return res;
}
