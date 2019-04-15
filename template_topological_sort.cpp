// topo sort can detect DIRECTED graph loop.
// UN-DIRECTED graph loop: union-find
// or DFS with visit() check but not father node!

class Solution {
public:
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    
    // topo sort has O(n) time complexity.
    // use 1 for completed visited.
    // use 0 for currently visiting, i.e., in stack.
    // use -1 as unknown status.
    
    vector<int> status(numCourses, -1);
    
    // since this graph is from 0 to n-1. 
    // Using the vector index as the node, 
    // And another dimension as the out edges
    vector<vector<int>> graph(numCourses, vector<int>());
    
    for(const auto& thePair : prerequisites) 
      graph[thePair.second].emplace_back(thePair.first);
      
    for(int i=0; i<graph.size(); ++i) 
      if(!doDFS(graph, status, i)) return false;
    
    return true;
  }
  
  bool doDFS(const vector<vector<int>>& graph, 
             vector<int>& status, 
             int curNode) {
    
    // already visited, ok.
    if(status[curNode] == 1) return true;
    
    // currently visiting in stack, so find loop.
    if(status[curNode] == 0) return false;
    
    // mark curNode as visiting
    status[curNode] = 0;
    
    for(const auto& next : graph[curNode])
      // find loop, return false
      if(!doDFS(graph, status, next)) return false;
    
    // mark curNode as visited
    status[curNode] = 1;

    // topo order needs to insert the curNode to the head.
    // i.e., first visited node ranked last.
    topoOrder_.insert(0, curNode);
    
    return true;
  }

private:
  vector<int> topoOrder_;
  
};
