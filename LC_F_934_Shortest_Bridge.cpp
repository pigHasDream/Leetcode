public:
  int shortestBridge(vector<vector<int>>& A) {
    const int row = A.size();
    const int col = A.front().size();
    
    vector<vector<int>> group1(row, vector<int>(col, 0));
    vector<vector<int>> group2(row, vector<int>(col, 0));
    int count1 = 0, count2 = 0;
    
    const vector<int> dir = {0,1,0,-1,0};
    
    vector<vector<int>> visit(row, vector<int>(col, 0));
    function<void(int,int, vector<vector<int>>&, int&)> doDFS =
      [&](int x, int y, vector<vector<int>>& group, int& count) {
      
      visit[x][y] = 1;
      for(int k=0; k<4; ++k) {
        int xx = x+dir[k];
        int yy = y+dir[k+1];
        
        if(xx<0 or xx>=row or yy<0 or yy>=col or visit[xx][yy])
          continue;
        
        if(A[xx][yy] == 0) {
          group[xx][yy] = 1;
          ++count;
          continue;
        }
        
        doDFS(xx,yy,group,count);
      }
    };
    
    bool found = false;
    for(int i=0; i<row; ++i) {
      for(int j=0; j<col; ++j)
        if(A[i][j] and visit[i][j] == 0) { 
          doDFS(i,j,group1,count1);
          found = true;
          break; 
        }
      if(found) break;
    }

    found = false;
    for(int i=0; i<row; ++i) {
      for(int j=0; j<col; ++j)
        if(A[i][j] and visit[i][j] == 0) { 
          doDFS(i,j,group2,count2);
          break; 
        }
      if(found) break;
    }
    
   if(count1 > count2)
     swap(group1, group2);
    
    queue<pair<int,int>> que;
    for(int i=0; i<row; ++i) 
      for(int j=0; j<col; ++j) 
        if(group1[i][j])
          que.emplace(i,j);

    int res = 1;
    while(que.size()) {
      for(int k=que.size(); k>0; --k) {
        auto [r, c] = que.front();
        que.pop();
        if(group2[r][c]) {
          return res;
        }
        
        for(int d=0; d<4; ++d) {
          int rr = r+dir[d];
          int cc = c+dir[d+1];

          if(rr<0 or rr>=row or cc<0 or cc>=col or visit[rr][cc])
            continue;
          
          visit[rr][cc] = 1;
          que.emplace(rr, cc);
        }
      }
      ++res;
    }
    
    return -1;
   
  }
};
