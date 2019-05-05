class Solution {
  vector<vector<int>> memo_;
  
  int minDist(const string& s, const string& t, int i, int j) {
    if(s.size() == i) return t.size()-j;
    if(t.size() == j) return s.size()-i;
    
    if(memo_[i][j] != -1) return memo_[i][j];
    
    int res = 0;
    if(s[i]==t[j]) {
      res = minDist(s, t, i+1, j+1);
    }
    else {
      res = 1 + min(min(minDist(s, t, i+1, j),
                        minDist(s, t, i, j+1)),
                    minDist(s, t, i+1, j+1));
    }
    
    return memo_[i][j] = res;
    
  }
  
public:
  int minDistance(string word1, string word2) {
    
    int size1 = word1.size();
    int size2 = word2.size(); 
    
    memo_.resize(size1, vector<int>(size2, -1));
    
    return minDist(word1, word2, 0, 0);
    
  }
};


// DP bottom up
int minDistance(string s, string t) {

	int size1 = s.size();
	int size2 = t.size();
	
  // dp[i][j] refers to converting s[0..i] to t[0..t] count
	vector<vector<int>> dp(size1+1, vector<int>(size2+1, 0));
  // base case is when one of the string is empty, we will
  // convert the full length of the other non-empty one.
	for(int i=0; i<=size1; ++i) dp[i][0] = i;
	for(int i=0; i<=size2; ++i) dp[0][i] = i;
	
	for(int i=1; i<=size1; ++i) {
		for(int j=1; j<=size2; ++j) {
      // if new letter the same, do nothing
			if(s[i-1] == t[j-1])
				dp[i][j] = dp[i-1][j-1];
      // if not the same, it can be 
      // replace: dp[i-1][j-1] to make i-th and j-th the same
      // insert: use the dp[i][j-1] 
      // delete: use the dp[i-1][j]
			else
				dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
		}
	}
	
	return dp[size1][size2] == 1;
}
