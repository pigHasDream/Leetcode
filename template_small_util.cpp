// -----------------------------------------------------
// Palindrome check
bool isPalindrome(const string& s, int start, int end) {
  for(int i=start, j=end; i<j; ++i, --j)
    if(s[i] != s[j]) return false;

  return true;
}

// -----------------------------------------------------
// Palindrome DP transitional check condition
// isPal[i][j]: if i~j is a palindrome
if (s[i] == s[j] and (i-j<2 or isPal[j+1][i-1]))
  return true;

// -----------------------------------------------------
// simultaneous check incremental numbers
int nthUglyNumber(int n) {

  // initially smaller size
	vector<int> dp(1,1);
	int i =0, j=0, k=0;
	
	while(dp.size() < n) {
		
    // gradually build up the vector
		dp.emplace_back(min(dp[i]*2, min(dp[j]*3, dp[k]*5)));
		
		if(dp.back() == dp[i]*2) ++i;
		if(dp.back() == dp[j]*3) ++j;
		if(dp.back() == dp[k]*5) ++k;
		
	}
	
	return dp.back();
}

// -----------------------------------------------------
// reading through each digit leter to form a number

int num = 0;
for(const auto& c : theString)
	if(isdigit(c)) num = num*10 + c-'0';


// -----------------------------------------------------
// use 1-d array or hash table to mimic a 3-d table
// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-546-remove-boxes/
unordered_map<int, int> map_;
int key = (l * d1 + r) * d2 + k;
map_[k] 
