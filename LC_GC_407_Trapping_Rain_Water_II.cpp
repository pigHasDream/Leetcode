class Solution {
public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    
    int row = heightMap.size();
    int col = heightMap.front().size();
    
    int maxLevel = 0;
    auto cmp = [](const auto& vec1, const auto& vec2) -> bool {
      if(vec1.front() == vec2.front()) return vec1.back() < vec2.back();
      if(vec1.front() > vec2.front()) return true;
      return false;
    };
    
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> que(cmp);
    
    const vector<int> dir{0,1,0,-1,0};
    vector<vector<int>> visit(row, vector<int>(col, 0));
    
    int res = 0; 
    
    for(int i=0; i<row; ++i) {
      que.emplace(vector<int>({heightMap[i][0], i, 0}));
      visit[i][0] = 1;
      que.emplace(vector<int>({heightMap[i][col-1], i, col-1}));
      visit[i][col-1] = 1;
    }
    
    for(int j=0; j<col; ++j) {
      que.emplace(vector<int>({heightMap[0][j], 0, j}));
      visit[0][j] = 1;
      que.emplace(vector<int>({heightMap[row-1][j], row-1, j}));
      visit[row-1][j] = 1;
    }
    
    while(que.size()) {
      auto top = que.top();
      que.pop();
      
      if(top.front() > maxLevel) {
        maxLevel = top.front();
      }
      else {
        res += maxLevel - heightMap[top[1]][top[2]];
      }
       
      for(int k=0; k<4; ++k) {
        int next_i = top[1] + dir[k];
        int next_j = top[2] + dir[k+1];
        
        if(next_i < 0 or next_i >= row or next_j < 0 or next_j >= col or visit[next_i][next_j]) 
          continue;
        
        que.emplace(vector<int>({heightMap[next_i][next_j], next_i, next_j}));
        visit[next_i][next_j] = 1;
      }
    }

    return res;
  }
};
