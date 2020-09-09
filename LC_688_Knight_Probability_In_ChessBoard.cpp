class Solution {
  vector<vector<vector<double>>> memo_;
public:
  double knightProbability(int N, int K, int r, int c) {
    memo_.assign(K+1, vector<vector<double>>(N, vector<double>(N,-1)));
    return doDFS(N, K, r, c)/pow(8,K);
  }
  
  double doDFS(int N, int K, int r, int c) {
    
    if(r<0 or c<0 or r>N-1 or c>N-1) return 0;
    // when K==0, that's the starting count = 1
    if(K == 0) return 1;
    if(memo_[K][r][c] != -1) return memo_[K][r][c];
    
    return memo_[K][r][c] = doDFS(N, K-1, r+1, c+2) + doDFS(N, K-1, r-2, c-1) +
                            doDFS(N, K-1, r+1, c-2) + doDFS(N, K-1, r-2, c+1) +
                            doDFS(N, K-1, r-1, c+2) + doDFS(N, K-1, r+2, c+1) +
                            doDFS(N, K-1, r-1, c-2) + doDFS(N, K-1, r+2, c-1);
  }
  
};


class Solution {
public:
  double knightProbability(int N, int K, int r, int c) {
    
    vector<pair<int,int>> dir{{2,1}, {2,-1}, {-2,1}, {-2,-1},
                              {1,2}, {1,-2}, {-1,2}, {-1,-2}};
    
    // at (x,y) and the remaining H steps, what is the 
    // count onboard
    double memo[26][26][101];
    memset(memo, -1, sizeof memo);
    
    // doDFS returns count on board
    function<double(int,int,int)> doDFS =
      [&](int x, int y, int step) -> double {
      
      if(step == K)
        return 1;
      
      double& ans = memo[x][y][step];
      if(ans >= 0) return memo[x][y][step];
      
      ans = 0;
      
      for(int s=0; s<8; ++s) {
        int nx = x+dir[s].first;
        int ny = y+dir[s].second;
        
        if(nx<0 or nx>=N or ny<0 or ny>=N) continue;
        
        ans += doDFS(nx, ny, step+1);
      }
      
      return ans;
    };

    return doDFS(r,c,0)/double(pow(8,K));
    
  }
};


class Solution {
public:
  double knightProbability(int N, int K, int r, int c) {
    // The bottom up solution is to accumulate for each position
    // What is the count up to now.
    // This is essentially a BFS process: start from the r, c source
    // gradually simulate each location and accumulate the final result.
    vector<vector<double>> dp(N, vector<double>(N, 0));
    // The starting count of being in chessboard is 1.
    dp[r][c] = 1;
    const vector<pair<int, int>> dir{{1,2}, {1,-2}, {-1,2}, {-1,-2}, 
                                     {2,1}, {2,-1}, {-2,1}, {-2,-1}};
    
    for(int k = K; k>0; --k) {
      vector<vector<double>> tmp(N, vector<double>(N, 0));
      for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++j) {
          for(int d=0; d<8; ++d) {
            int xx = i+dir[d].first;
            int yy = j+dir[d].second;
            if(xx>=0 and xx<N and yy>=0 and yy<N)
              tmp[xx][yy] += dp[i][j];
          }
        }
      }
      swap(tmp, dp);
    }
    
    double res = 0;
    for(const auto& row : dp)
      for(const auto& e : row)
        res += e;
    
    return res/pow(8,K);
  }
};
