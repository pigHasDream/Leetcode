class Solution {
  public:
  int minCost(vector<vector<int>>& grid)  {
    
    // Main idea is BFS + DFS, O(MN)
    // Overall a greedy fashion never visit twice
    int m = grid.size(), n = grid.front().size();
    vector<vector<int>> visited(m, vector<int>(n, 0));

    // The DFS to find already connected nodes to set
    function<void(int,int,vector<pair<int,int>>&)> 
      doDFS = [&] (int x, int y,
                   vector<pair<int,int>>& passSet) { 

      if (x<0 or x>=m or y<0 or y>=n) return;
      if (visited[x][y]==1) return;

      visited[x][y] = 1;
      passSet.emplace_back(x,y);

      int i,j;
      if (grid[x][y]==1)      { i=x,    j=y+1; }
      else if (grid[x][y]==2) { i=x,    j=y-1; }
      else if (grid[x][y]==3) { i=x+1,  j=y; }
      else if (grid[x][y]==4) { i=x-1,  j=y; }

      doDFS(i,j,passSet);
    };
    
    vector<pair<int,int>> initQue;
    doDFS(0,0,initQue);
    
    // Que for BFS to gradually expand
    queue<pair<int,int>> que;
    for(const auto& x: initQue) 
      que.emplace(x);

    int step = 0;
    const vector<int> dir{0,1,0,-1,0};
    
    while (que.size()) {
      for(int h=que.size(); h>0; --h) {
        
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        
        // termination!
        if(x == m-1 and y == n-1)
          return step;
        
        for (int k=0; k<4; k++) {
          int nx = x+dir[k];
          int ny = y+dir[k+1];
          
          if (nx<0 or nx>=m or ny<0 or ny>=n)
            continue;
          if (visited[nx][ny])
            continue;

          // After flip, get all the new reachable!
          vector<pair<int,int>> nxtQue;
          doDFS(nx,ny,nxtQue);
          
          for(const auto& x : nxtQue) 
            que.emplace(x);                        
        }
      }
      ++step;
    }
    
    return 0;
  }
};
