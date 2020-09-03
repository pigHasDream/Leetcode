class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));
    
    vector<pair<int,int>> dir = {{0,1},{1,0}, {0,-1}, {-1,0}};
    
    auto isOK = [&](int x, int y) {
      return x>=0 and x<n and y>=0 and y<n and res[x][y] == 0;
    };
    
    int idx = 1;
    int facing = 0;
    int row = 0;
    int col = -1;
    int row_delta = 0;
    int col_delta = 1;
    
    while(isOK(row+row_delta, col+col_delta)) {
      while(isOK(row+row_delta, col+col_delta)) {
        res[row+=row_delta][col+=col_delta] = idx++; 
      }
      ++facing;
      row_delta = dir[facing%dir.size()].first;
      col_delta = dir[facing%dir.size()].second;
    }

    return res;
  }
};
