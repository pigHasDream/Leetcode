class Solution {
public:
  int orangesRotting(vector<vector<int>>& grid) {
    
    const int dir[5] = {0,1,0,-1,0};
    int row = grid.size();
    int col = grid.front().size();
    
    // Key is to put all originally rotten oranges 
    // into the que, and do BFS.
    // This will naturally spread outwards Simultaneously!!
    queue<pair<int,int>> que;
    int fresh = 0;
    int step = 0;
    
    for(int i=0; i<row; ++i)
      for(int j=0; j<col; ++j)
        if(grid[i][j] == 2)
          que.emplace(i, j);
        else 
          fresh += grid[i][j];
    
    while(que.size() and fresh > 0) {
      ++step;
      for(int i=que.size(); i>0; --i) {
        auto top = que.front();
        que.pop();
        
        for(int i=0; i<4; ++i) {
          int x = top.first+dir[i];
          int y = top.second+dir[i+1];
          if(x<0 or x>=row or y<0 or y>=col or grid[x][y] != 1)
            continue;
          que.emplace(x,y);
          grid[x][y] = 2;
          --fresh;
        }
      }
    }
    
    return fresh > 0 ? -1 : step;

  }
};
