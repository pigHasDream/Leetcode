class Solution {
public:
  int numMusicPlaylists(int N, int L, int K) {
    // dp[i][j] := a list of j songs is made of i songs satisfying the "K" constraint
    // dp[i][j] = dp[i-1][j-1]*(N-i+1) + dp[i][j-1]*max(0, i-K);

    constexpr int mod = 1e9+7;
    vector<vector<long>> dp(N+1, vector<long>(L+1, 0));
    // Initial state here
    dp[0][0] = 1;
    
    for(int j=1; j<=L; ++j) {
      for(int i=1; i<=min(j, N); ++i) {
        dp[i][j] = ((dp[i-1][j-1]*(N-i+1))%mod + (dp[i][j-1]*max(0, i-K))%mod)%mod;
      }
    }   

    return dp.back().back();
  }
};

