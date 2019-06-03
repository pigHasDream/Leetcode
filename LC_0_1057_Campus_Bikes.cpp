class Solution {
public:
  vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
    
    // define the element to be pushed into the pq is a {hdist, worker, bike};
    // Note that priority_queue is doing opposite to the comparison!
    auto cmp = [](const auto& a, const auto& b) {
      if(a[0] == b[0]) {
        if(a[1] == b[1]) return a[2] > b[2];
        return a[1] > b[1];
      }
      return a[0] > b[0];
    };
    
    priority_queue<array<int,3>, vector<array<int, 3>>, decltype(cmp)> que(cmp);
    
    for(int i=0; i<workers.size(); ++i) {
      for(int j=0; j<bikes.size(); ++j) {
        array<int,3> elem = {abs(workers[i][0]-bikes[j][0]) + abs(workers[i][1]-bikes[j][1]), i, j};
        que.emplace(elem);
      }
    }
    
    vector<int> res(workers.size(), -1);
    vector<int> used(bikes.size(), 0);
    while(que.size()) {
      auto top = que.top(); que.pop();
      int widx = top[1];
      int bidx = top[2];
      
      if(res[widx] == -1 and used[bidx] == 0) {
        res[widx] = bidx;
        used[bidx] = 1; 
      }
    }
    
    return res;
  }
};
