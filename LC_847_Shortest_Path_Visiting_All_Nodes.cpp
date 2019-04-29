class Solution {
public:
  int shortestPathLength(vector<vector<int>>& graph) {
    // Key to this question is the state definition!
    // How to define visited states to avoid deadlock
    // or useless checks!
    // Here we use a bitmask to record the states
    // And for each node, there are 2^N states, so
    // need to use vector to mark wether visited.
  
    // After the state definition, it's a typical BFS loop
    
    int size = graph.size();
    const int finalState = (1<<size) -1;
    
    queue<pair<int, int>> que;
    // The visit[x][y]: x refers to curNode
    // y refers to 1 of the 2^size states
    // the value refers to wether visited or not
    vector<vector<int>> visit(size, vector<int>(1<<size,0));
    
    for(int i=0; i<size; ++i)
      que.push({i, 1<<i});
    
    int step = 0;
    while(que.size()) {
      for(int k=que.size(); k>0; --k) {
        auto top = que.front();
        que.pop();
        
        int node = top.first;
        int state = top.second;
        if(state == finalState) return step;
        if(visit[node][state]) continue;
        visit[node][state] = 1;
        
        for(auto next : graph[node]) {
          que.push({next, state | (1<<next)});
        }
      }
      ++step;
    }
    
    return -1;
  }
};
