class Solution {
  int finish_ = 0;
  int row_ = -1;
  int col_ = -1;
  vector<int> dir_ = {0, 1, 0, -1, 0};
  
  vector<vector<int>> memo_;
  
public:
  int uniquePathsIII(vector<vector<int>>& grid) {
    int start = -1, end = -1;
    row_ = grid.size();
    if(row_ == 0) return 0;
    col_ = grid[0].size();
    int visit = 0;
    finish_ = (1<< (row_*col_)) - 1;
    
    for(int i=0; i<row_; ++i) {
      for(int j=0; j<col_; ++j) {
        if(grid[i][j] == 1) start = i*col_+j;
        if(grid[i][j] == 2) end = i*col_+j;
        if(grid[i][j] == -1) visit |= (1 << (i*col_+j));
      }
    }
    
    memo_.resize(row_*col_, vector<int>(1<<(row_*col_), -1));
    
    return doDFS(grid, start, end, visit | (1<<start));
  }
  
  int doDFS(vector<vector<int>>& grid, int cur, int end, int visit) {
    
    if(cur == end and visit == finish_) return 1;
    if(memo_[cur][visit] != -1) return memo_[cur][visit];
    
    int y = cur/col_;
    int x = cur%col_;
    
    int ret = 0;
    for(int i=0; i<4; ++i) {
      int yy = y+dir_[i];
      int xx = x+dir_[i+1];
      int next = yy*col_+xx;
      
      if(yy<0 or yy>row_-1 or xx<0 or xx>col_-1 or 
         grid[yy][xx] == 1 or ((visit >> next) & 1))
        continue;
      
      ret += doDFS(grid, next, end, visit | (1<<next));
    }
    
    return memo_[cur][visit] = ret;
  }
  
};
