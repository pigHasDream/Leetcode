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

// N^2 typical DP: 2 level
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
// longest palindrom substr
// -------------------------------



// -------------------------------
// longest common subsequence
// -------------------------------


// -------------------------------
// longest common substr
// -------------------------------

