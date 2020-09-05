class Solution {
public:
  string shortestCommonSupersequence(string str1, string str2) {
    int sz1 = str1.size();
    int sz2 = str2.size();
    
    vector<vector<int>> dp(sz1+1, vector<int>(sz2+1, 0));
    
    for(int i=1; i<=sz1; ++i) {
      for(int j=1; j<=sz2; ++j) {
        if(str1[i-1] == str2[j-1]) {
          dp[i][j] = dp[i-1][j-1] + 1;
        }
        else {
          dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
      }
    }

    deque<char> res;
    int i=sz1;
    int j=sz2;
    
    while(i or j) {
      char c;
      if(i==0) c = str2[--j];
      else if(j==0) c = str1[--i];
      else if(str1[i-1] == str2[j-1]) c = str1[--i] = str2[--j];
      else if(dp[i][j] == dp[i-1][j]) c = str1[--i];
      else if(dp[i][j] == dp[i][j-1]) c = str2[--j];
      res.emplace_front(c);
    }

    return {res.begin(), res.end()};
  }
};

