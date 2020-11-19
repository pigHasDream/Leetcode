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
    
    // all nodes can start!
    for(int i=0; i<size; ++i)
      que.emplace(i, 1<<i);
    
    int step = 0;
    while(que.size()) {
      for(int k=que.size(); k>0; --k) {
        auto [node, start] = que.front();
        que.pop();
        
        if(state == finalState) 
          return step;
        if(visit[node][state]) 
          continue;
        visit[node][state] = 1;
        
        for(const auto& nxt : graph[node]) {
          que.push({nxt, state | (1<<next)});
        }
      }
      ++step;
    }
    
    return -1;
  }
};


// Note that this problem can visit the same node multiple times!
// So, the repeatation check is just to check the same state and new node!
// We don't need to check state | (1<<nxt), as this may have re-visited!

class Solution {
public:
  int shortestPathLength(vector<vector<int>>& graph) {
    
    // <node, curState>
    queue<pair<int, int>> que;
    // visit[node][state]
    vector<vector<int>> visit(graph.size(),
                        vector<int>(1<<graph.size(), 0));

    for(int i=0; i<graph.size();++i)
      que.emplace(i, 1<<i);
    
    int step = 0;
    
    while(que.size()) {
      for(int k=que.size(); k>0; --k) {
        auto [node, state] = que.front();
        que.pop();
        if(state == (1<<graph.size())-1)
          return step;
        
        if(visit[node][state]) continue;
        visit[node][state] = 1;

        for(const auto& nxt : graph[node]) {
          que.emplace(nxt, state | (1<<nxt));
        }
      }
      ++step;
    }

    return -1;
  }
};
