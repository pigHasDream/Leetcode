// Palindrome check
bool isPalindrome(const string& s, int start, int end) {
  for(int i=start, j=end; i<j; ++i, --j)
    if(s[i] != s[j]) return false;

  return true;
}

// Palindrome DP transitional check condition
// isPal[i][j]: if i~j is a palindrome
if (s[i] == s[j] and (i-j<2 or isPal[j+1][i-1]))
  return true;

// Valid parenthenese
