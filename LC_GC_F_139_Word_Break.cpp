class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    
    vector<int> dp(s.size()+1, 0);
    dp.front() = 1;
    
    for(int len=1; len<=s.size(); ++len) {
      for(int i=0; i<len; ++i) {
        if(dp[i] and dict.count(s.substr(i, len-i))) {
          dp[len] = 1;
        }
      }
    }

    return dp.back() > 0;
  }
};
