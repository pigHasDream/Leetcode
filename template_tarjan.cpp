// Key to Tarjan's algorithm is to DFS and when hitting a back edge, we know there
// is a loop and we find the SCC.
// So, we use the low link concept to remember the timestamp of visiting a node and 
// when revisiting the same node, we update the smaller timestamp to current node!
//
// Lowlink: the smallest id that current node can reach to by DFS. If there is no cycle,
// the lowlink == curr id, otherwise we find a back edge to upstream node.

// This is Tarjan's algo to find the bridge!
// To find the strongly connected components, we need to modify a little bit
//
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
          // below is the key bridge condition!
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

// To find Strongly connected components, we need to modify above algo a little bit.
// Key thing is to do the low link update only to those nodes that are on the stack!
// We introduce another stack vector on top of those used in above bridge algo.

vector<vector<int>> findSCC(int n, vector<vector<int>>& connections) {

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

  // BELOW are newly added for Tarjan to find SCC
  vector<int> onStack(n, false);
  stack<int> stc;
  
  function<void(int)> doDFS = [&] (int node) {

    visit[node] = 1;
    stc.emplace(node);
    onStack[node] = true;
    
    low[node] = ids[node] = globalIdx++;
    
    for(const auto& nxt : graph[node]) {
      if(not visit[nxt]) 
        doDFS(nxt);
      // Only udpate the lowlink value with the nxt in the stack!
      if(onStack[nxt]) {
        low[node] = min(low[node], low[nxt]);
      }
    }

    // This is the root of one component
    // Now poping out all the nodes of same component from the stack
    if(ids[node] == low[node]) {
      vector<int> component;
      while(stc.size()) {
        auto top = stc.top(); stc.pop();

        component.emplace_back(top);
        onStack[top] = false;
        low[top] = ids[node];
        if(top == node) break;
      }
      res.emplace_back(component);
    }

  };
  
  // top level to check each component in case they are already separated
  for(int i=0; i<n; ++i) {
    if(visit[i]==0)
      doDFS(i);
  }
  
  return res;
}
