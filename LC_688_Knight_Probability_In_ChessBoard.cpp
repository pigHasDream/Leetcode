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
    // The bottom up solution is to accumulate for each position
    // What is the count up to now.
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
