class Solution {
  struct DataCL {
    DataCL(int r, int c, int min) :
      r_{r}, c_{c}, theMin_(min) {}
    int r_;
    int c_;
    int theMin_;
  };
  
public:
  int maximumMinimumPath(vector<vector<int>>& A) {
    const int row = A.size();
    const int col = A.front().size();
    const vector<int> dir = {0,1,0,-1,0};
    
    auto canReach = [&](int bound) {
      queue<DataCL> que;
      vector<vector<int>> visit(row, vector<int>(col,0));
      que.emplace(DataCL{0,0,A.front().front()});
      visit[0][0]=1;
      
      while(que.size()) {
        for(int k=que.size(); k>0; --k) {
          auto [r,c,theMin] = que.front();
          que.pop();
          // Below needs to be careful: it still needs to compare with
          // the bound!
          if(r==row-1 and c==col-1)
            return theMin >= bound;
          
          for(int d=0; d<4; ++d) {
            int nr = r + dir[d];
            int nc = c + dir[d+1];
            
            if(nr<0 or nr>=row or nc<0 or nc>=col or visit[nr][nc])
              continue;
            if(A[nr][nc] < bound) continue;
            
            visit[nr][nc] = 1;
            que.emplace(DataCL{nr, nc, min(A[nr][nc], theMin)});
          }
        }
      }
      
      return false;
    };
    
    int left = 0, right = 1e9+1;
    while(left < right) {
      int mid = left+(right-left)/2;
      if(canReach(mid)) {
        left = mid+1;
      }
      else {
        right = mid;
      }
    }

    return left-1;
  }
};
