// Prim algo and Dijkstra look similar
// Key differences are 2 folds:
// 1. Prim uses visit check in case of disconnected components, Dijkstra uses newDist > curDist + edgeCost as filter
// 2. Prim cost is each edge raw cost, and Dijkstra is so far path cost 

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

// Below is the 1135 MST problem using Prim.

class Solution {
public:
  int minimumCost(int N, vector<vector<int>>& connections) {
    
    vector<vector<pair<int,int>>> graph(N+1);
    for(const auto& e : connections) {
      graph[e[0]].emplace_back(e[2], e[1]);
      graph[e[1]].emplace_back(e[2], e[0]);
    }
    
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que;
    que.emplace(0, 1);
    vector<int> visited(N+1, 0);
     
    int res = 0;
    while(que.size()) {
      auto top = que.top(); que.pop();
      auto node = top.second;
      
      if(visited[node]) continue;
      res += top.first;
      
      visited[node] = 1;
      
      for(const auto & nxt : graph[node]) {
        auto edgeCost = nxt.first;
        auto nxtNode = nxt.second;
        que.emplace(edgeCost, nxtNode);
      }
    }
    
    for(int i=1; i<visited.size(); ++i) {
      if(visited[i] == 0) return -1;
    }
    
    return res;
  }
};
