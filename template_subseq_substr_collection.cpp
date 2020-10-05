// -------------------------------
// longest increasing subsequence
// -------------------------------
// N^2 typical DP: 2 level loop,
// 1-D space. 
// This is stricly increasing!!!
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
int lengthOfLIS(vector<int>& nums) {
	// the nlog(n) solution is using patience sorting
	// https://www.cs.princeton.edu/courses/archive/spring13/cos423/lectures/LongestIncreasingSubsequence.pdf
	// Key observation:
	// patience sorting, the top card of each pile forms an increasing order by following the rule.
  // each pile itself decreases, if new card cannot be put, put it in new pile
  // 
  //
  // Alternatively! Think about greedy!
  // If the new number n is not able to extend the current res lenghth,
  // the best it can do is to LOWER the height of the elements in res.
  // So that later on it may have more chance to see a drop!

	vector<int> res;
	for(const auto& n : nums) {
		auto iter = lower_bound(res.begin(), res.end(), n);
		if(iter == res.end()) res.emplace_back(n);
		else *iter = n;
	}

	return res.size();

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

// Construct the longest common subsequence
string LCS_print(string str1, string str2) {
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

  // Here we construct the LCS from back to front
	deque<char> res;
	int i=sz1;
	int j=sz2;

	while(i and j) {
		char c;
		if(str1[i-1] == str2[j-1]) c = str1[--i] = str2[--j];
		else if(dp[i][j] == dp[i-1][j]) --i;
		else if(dp[i][j] == dp[i][j-1]) --j;

		res.emplace_front(c);
	}

	return {res.begin(), res.end()};
}
// -------------------------------
// longest common substr
// -------------------------------
// This can also be solved by binary search 
// and compare. Nlog(N)
int longest_common_substring(string p, string q){

  int m =  p.size(), n =  q.size();

  vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
  int res = 0;

  for(int i=1; i<=m; ++i){
    for(int j=1; j<=n; ++j){
      // only when they match, we contiue
      // otherwise, keep 0 as the len.
      if(p[i-1] == q[j-1])
        dp[i][j] = dp[i-1][j-1] + 1;

      res = max(res, dp[i][j]);
    }
  }

  return res;
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


// -------------------------------
// shortest common supersequnce
// -------------------------------
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

  // similar to construct LCS, but need to include extra sequence
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
