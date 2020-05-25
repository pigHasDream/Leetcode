// -------------------------------
// longest increasing subsequence
// -------------------------------

// NlogN solution, keeps an increasing
// subseq array, and only update 
// to the last element

int lengthOfLIS(vector<int>& nums) {
  vector<int> res;

  for(int i=0; i<nums.size(); i++) {
    auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
    if(it==res.end()) res.emplace_back(nums[i]);
    else *it = nums[i];
  }

  return res.size();
}

// ---------------

// N^2 typical DP: 2 level loop,
// 1-D space. 
int lengthOfLIS(vector<int>& nums) {

  int size = nums.size();
  vector<int> dp(size, 1);
  
  for(int i=0; i<size; ++i) {
    for(int j=0; j<i; ++j) {
      dp[i] = max(dp[i], nums[i] > nums[j] ? dp[j] + 1 : 0);
    }
  }

  return *max_element(dp.begin(), dp.end());
}

// -------------------------------
// longest common subsequence
// -------------------------------
int longest_common_subsequence(string p, string q){

  int m = p.size(), n = q.size();

  vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

  for(int i=1; i<=m; ++i){
    for(int j=1; j<=n; ++j){
      if(p[i-1] == q[j-1])
        dp[i][j] = dp[i-1][j-1] + 1;
      else
        dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
    }
  }

  return dp[m][n];
}

// -------------------------------
// longest common substr
// -------------------------------
// This can also be solved by binary search 
// and compare. Nlog(N)
int longest_common_substring(string p, string q){

  int m =  p.size(), n =  q.size();

  vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

  for(int i=1; i<=m; ++i){
    for(int j=1; j<=n; ++j){
      if(p[i-1] == q[j-1])
        dp[i][j] = dp[i-1][j-1] + 1;
      else
        dp[i][j] = 0;
    }
  }

  return dp[m][n];
}

// -------------------------------
// longest palindrome subsequence
// -------------------------------
int longestPalindromeSubseq(string s) {
  int length = s.size();
  vector<vector<int>> dp(length, vector<int>(length, 0));
  
  for(int len=1; len<=length; ++len) {
    for(int i=0; i<=length-len; ++i) {

      int j = i + len - 1;

      if(len == 1) {
        dp[i][j] = 1;
        continue;
      }
      
      if(s[i] == s[j]) 
        dp[i][j] += dp[i+1][j-1] + 2;
      else 
        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
      
    }
  }
  
  return dp[0][length-1];
}


// -------------------------------
// longest palindrome substr
// -------------------------------

// -------------------------------
// count palindrome subsequence
// -------------------------------

// -------------------------------
// count palindrome substr
// -------------------------------

// -------------------------------
// Check for is s is subseq of t
// -------------------------------
bool isSubsequence(string s, string t) {
  // 2 pointers, move left when match, 
  // always move right pointer.
  
	int left = 0, right = 0;
	
	while(left<s.size() and right<t.size()) {
		if(s[left] == t[right]) ++left;
    ++right;
	}
	
	return left == s.size();
}
