class Solution {
  public:
  int largestIsland(vector<vector<int>>& grid) {
    const int row = grid.size();
    const int col = grid.front().size();
    const vector<int> dir{0,1,0,-1,0};
    
    unordered_map<int,int> idx2count;
    
    // Coloring each group!
    // Or use Union-Find!
    function<int(int,int,int)> doDFS = 
      [&](int r, int c, int idx) -> int {
      grid[r][c] = idx;
      
      int ret = 1;
      for(int d=0; d<4; ++d) {
        int nr = r+dir[d];
        int nc = c+dir[d+1];
        
        if(nr<0 or nr>=row or nc<0 or nc>=col)
          continue;
        
        if(grid[nr][nc]==1) {
          ret += doDFS(nr, nc, idx);
        }
      }
      
      return ret;
    };
    
    // get the index to count map for each group
    for(int i=0, index=2; i<row; ++i) {
      for(int j=0; j<col; ++j) {
        if(grid[i][j] == 1) {
          idx2count[index] = doDFS(i, j, index);
          ++index;
        }
      }
    }
    
    // if there is any 0, flip one by one and check its 
    // neighbor to get the merged count!
    // Watch out that if some of the neighbor cells are 
    // already marked as 1.
    int res = 0;
    for(int i=0; i<row; ++i) {
      for(int j=0; j<col; ++j) {
        if(grid[i][j] == 0) {
          int curMax = 0;
          unordered_set<int> neighbor;
          for(int k=0; k<4; ++k) {
            int ni = i+dir[k];
            int nj = j+dir[k+1];
            if(ni<0 or ni>=row or nj<0 or nj>=col)
              continue;
              
            if(grid[ni][nj]>1) 
              neighbor.emplace(grid[ni][nj]);
          }
          
          for(const auto& n : neighbor) 
            curMax += idx2count[n];
          
          res = max(res, curMax+1);
        }
      }
    }
    
    // there is a case where all cells are filled, 
    // res needs to take the full size.
    return res == 0 ? row*col : res;
  }
};
