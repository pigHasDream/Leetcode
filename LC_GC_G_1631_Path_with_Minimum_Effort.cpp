// Brute force Back tracking
class Solution {
public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    
    int row = heights.size();
    int col = heights.front().size();
    
    const int inf = 1e6+1;
    int res = inf;
    vector<int> dir{0,1,0,-1,0};
    
    vector<vector<int>> visit(row, vector<int>(col, 0));
    
    function<void(int,int,int)> doDFS =
      [&](int r, int c, int curMin) {
      
      if(r == row-1 and c == col-1) {
        res = min(res,curMin);
        return;
      }
      
      for(int k=0; k<4; ++k) {
        int nr = r + dir[k];
        int nc = c + dir[k+1];
        
        if(nr<0 or nr>=row or nc<0 or nc>=col or visit[nr][nc]) continue;
        
        int diff = abs(heights[nr][nc]-heights[r][c]);
        
        if(diff > res) continue;
        
        visit[nr][nc] = 1;
        doDFS(nr, nc, max(curMin, diff));
        visit[nr][nc] = 0;
      }
    };

    visit[0][0] = 1;
    doDFS(0, 0, 0);
    
    return res;
  }
};


// Dijkstra-like
class Solution {
  struct DataCL {
    int r_;
    int c_;
    int diff_;
  };
public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    
    int row = heights.size();
    int col = heights.front().size();
    
    vector<int> dir{0,1,0,-1,0};
    auto cmp = [&](const auto& a, const auto& b) {
      return a.diff_ > b.diff_;
    };
    
    priority_queue<DataCL, vector<DataCL>, decltype(cmp)> que(cmp);
    vector<vector<int>> visit(row, vector<int>(col, 0));
    // Dijkstra requires a separate "cost" matrix/graph
    // along with a visit matrix/graph!
    vector<vector<int>> diffGraph(row, vector<int>(col, 1e6+1));
    que.emplace(DataCL{0,0,0});
    diffGraph[0][0] = 0;
    
    int res = 1e6+1;
    
    while(que.size()) {
      auto top = que.top();
      que.pop();
      // Dijkstra algo, the visit must be set at the pop time
      // Becuase otherwise we may not visit the same node again!
      // even if it's not evaluated!
      visit[top.r_][top.c_] = 1;
      
      if(top.r_ == row-1 and top.c_ == col-1)
        return top.diff_;
      
      for(int d=0; d<4; ++d) {
        int nr = top.r_ + dir[d];
        int nc = top.c_ + dir[d+1];
        
        if(nr<0 or nr>=row or nc<0 or nc>=col or visit[nr][nc])
          continue;
        
        int newDiff = max(top.diff_, abs(heights[top.r_][top.c_]-heights[nr][nc]));
        if(newDiff > diffGraph[nr][nc]) continue;
        
        que.emplace(DataCL{nr,nc,newDiff});
        diffGraph[nr][nc] = newDiff;
      }
    }
    
    /* return diffGraph.back().back(); */
    // never gets to this line!
    return -1;
  }
};


// Binary search + BFS
class Solution {
public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    
    int row = heights.size();
    int col = heights.front().size();
    
    vector<int> dir{0,1,0,-1,0};
    
    auto canReach = [&](int bound) {
      queue<pair<int,int>> que;
      vector<vector<int>> visit(row, vector<int>(col,0));
      
      que.emplace(0,0);
      visit[0][0] = 1;
      
      while(que.size()) {
        for(int k=que.size(); k>0; --k) {
          auto [r, c] = que.front();
          que.pop();
          
          if(r==row-1 and c==col-1)
            return true;
          
          for(int d=0; d<4; ++d) {
            int nr = r + dir[d];
            int nc = c + dir[d+1];
            
            if(nr<0 or nr>=row or nc<0 or nc>=col or
               visit[nr][nc] or abs(heights[nr][nc]-heights[r][c]) > bound)
              continue;
            
            visit[nr][nc] = 1;
            que.emplace(nr, nc);
          }
        }
      }
      
      return false;
    };
    
    const int inf = 1e6+1;
    int left = 0, right = inf;
    while(left < right) {
      int mid = left + (right-left)/2;
      if(canReach(mid)) {
        right = mid;
      }
      else {
        left = mid+1;
      }
    }
      
    return right;
  }
};
