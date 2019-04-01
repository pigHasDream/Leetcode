class Solution {
public:
  void wallsAndGates(vector<vector<int>>& rooms) {
    int row = rooms.size();
    if(row ==0) return;
    int col = rooms[0].size();
    
    queue<pair<int,int>> que_;
    const vector<int> dir{0,1,0,-1,0};
    
    for(int i=0; i<row; ++i) {
      for(int j=0; j<col; ++j) {
        if(rooms[i][j] == 0)
          que_.push({i,j});
      }
    }
    
    while(que_.size()) {
      auto top = que_.front();
      que_.pop();
      int dist = rooms[top.first][top.second];

      for(int k=0; k<4; ++k) {
        int x = top.first+dir[k];
        int y = top.second+dir[k+1];

        if(x>=0 and x<row and y>=0 and y<col and rooms[x][y] >0) {
          if(rooms[x][y] > dist+1) {
            rooms[x][y] = dist+1;
            que_.push({x,y});
          }
        }
      }
    }
  }
};
