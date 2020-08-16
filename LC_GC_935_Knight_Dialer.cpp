class Solution {
public:
  int knightDialer(int N) {
    const int mod = 1e9+7;
    vector<vector<int>> validMove = {
      {4,6},
      {6,8},
      {7,9},
      {4,8},
      {0,3,9},
      {},
      {0,1,7},
      {2,6},
      {1,3},
      {2,4},
    };
    
    vector<vector<int>> memo(10, vector<int>(N+1, -1));
    
    function<int(int,int)> doDFS = [&] (int n, int k) {
      if(k==1) {
        return 1;
      }
      
      if(memo[n][k]!=-1)
        return memo[n][k];
      
      int ret = 0; 
      for(const auto& nxt : validMove[n]) {
        ret = (ret + doDFS(nxt, k-1) % mod) % mod;
      }
      
      return memo[n][k] = ret;
    };
    
    int res = 0;
    for(int i=0; i<=9; ++i)
      res = (res + doDFS(i, N) % mod) % mod;

    return res;
  }
};

