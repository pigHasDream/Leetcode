class Solution {
public:
  int maxKilledEnemies(vector<vector<char>>& grid) {
    int row = grid.size();
    if(row == 0) return 0;
    
    int col = grid[0].size();
    
    // Get 4 matrix recording the counts from left most, right most,
    // up most, down most to current i,j position.
    // Note how we collect the numbers.
    
    // 1. When hitting W or starting from beginning, we have 0
    // 2. Everytime we hit an E, we increase by one, otherwise continue;
    // 3. The '0' empty position is checked in the final stage!!
    
    vector<vector<int>> vu(row, vector<int>(col, 0)), vd=vu, hl=vu, hr=vu;
    
    for(int i=0; i<row; ++i){
      for(int j=0; j<col; ++j) {
        int t = (j == 0 or grid[i][j] == 'W') ? 0 : hl[i][j-1];
        hl[i][j] = (grid[i][j] == 'E') ? t+1 : t;
      }
      
      for(int j=col-1; j>=0; --j) {
        int t = (j == col-1 or grid[i][j] == 'W') ? 0 : hr[i][j+1];
        hr[i][j] = (grid[i][j] == 'E') ? t+1 : t;
      }
    }
    
    for(int j=0; j<col; ++j) {
      for(int i=0; i<row; ++i){
        int t = (i == 0 or grid[i][j] == 'W') ? 0 : vu[i-1][j];
        vu[i][j] = (grid[i][j] == 'E') ? t+1 : t;
      }
      
      for(int i=row-1; i>=0; --i){
        int t = (i == row-1 or grid[i][j] == 'W') ? 0 : vd[i+1][j];
        vd[i][j] = (grid[i][j] == 'E') ? t+1 : t;
      }
    }
    
    int res = 0;
    for(int i=0; i<row; ++i)
      for(int j=0; j<col; ++j)
        // Note that we check here the '0'!!
        // So only 0 position is valid to be updated with res!!
        if(grid[i][j] == '0')
          res = max(res, vu[i][j] + vd[i][j] + hl[i][j] + hr[i][j]);

    return res;
  }
};
