class Solution {
public:
  string minWindow(string S, string T) {
    
    int sizeS = S.size(), sizeT = T.size();
    // use double sequence DP
    // dp[i][j] := the min subsequence length of i-th position in S string 
    // using i-th bit that can cover T string at j-th position!
    S = "#"+S;
    T = "#"+T;
    
    vector<vector<int>> dp(sizeS+1, vector<int>(sizeT+1, 0));
    const int inf = 1e8;
    
		// the boundary condition is checked through the subscription
    // of dp[i-1][j-1] in the loop!
    // This DP transition actually has inf or numbers mixed in the 
    // DP table! inf here refers to invalid!
    // any real number may be pointing to the real results!
    
    for(int i=1; i<=sizeT; ++i)
      dp[0][i] = inf;
    
    for(int i=1; i<=sizeS; ++i) {
      for(int j=1; j<=sizeT; ++j) {
        if(S[i]==T[j]) {
          dp[i][j] = dp[i-1][j-1] + 1;
        }
        else {
          // per definition, if i-th is not the same,
          // we have to rely on the earlier dp[i-1][j],
          // BUT, because we require to use i-th bit by definition!
          // So, we also add a 1 to the dp[i][j];
          dp[i][j] = dp[i-1][j] + 1;
        }
      }
    }
    
    int minLen = inf, pos = -1;
    for(int i=1; i<=sizeS; ++i) {
      if(dp[i][sizeT] < minLen) {
        minLen = dp[i][sizeT];
        pos = i;
      }
    }
    
    if(minLen >= inf) 
      return "";
    else 
      return S.substr(pos-minLen+1, minLen);
    
  }
};
