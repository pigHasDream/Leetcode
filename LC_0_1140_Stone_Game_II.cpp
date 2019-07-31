class Solution {
public:
  int stoneGameII(vector<int>& piles) {
    const int n = piles.size();
    vector<vector<int>> memo(n, vector<int>(n, -1));
    // reverse order prefix sum from n-1 down to 0
    vector<int> sum(n+1, 0);
    
    for(int i=n-1; i>=0; --i) 
      sum[i] = sum[i+1] + piles[i];
    
    function<int(int,int)> doDFS = [&](int idx, int M) {
      if(idx+2*M>n) return sum[idx];
      if(memo[idx][M] != -1) return memo[idx][M];
      
      int cur = 0;
      for(int i=1; i<=2*M; ++i) {
        // doDFS always returns the current player's max value!
        // then all it does is to use the remaining total stones'
        // value subtract the next player's move. 
        
        cur = max(cur, sum[idx] - doDFS(idx+i, max(i, M)));
      }
      
      return memo[idx][M] = cur;
    };

    return doDFS(0,1);
  }
};
