class Solution {
public:
  int longestValidParentheses(string s) {
    // use stack to get the longest parenthese
    // later check the length!
    // The Stack only holds the "(" and will pop 
    // once gets paired!
    
    // First pass to mark all the valid parentheses 
    // to be "*". 
    // Use stack to do the check which is always good!
    stack<int> stc;
    for(int i=0; i<s.size(); ++i) {
      if(s[i]=='(') stc.emplace(i);
      else if(stc.size()) {
        s[stc.top()] = s[i] = '*';
        stc.pop(); 
      }
    }
    
    // Second pass to check the longest subarray 
    // with "*"!
    int curLen = 0, maxLen = 0;
    for(int i=0; i<s.size(); ++i) {
      if(s[i]=='*') {
        ++curLen;
        maxLen = max(maxLen, curLen);
      }
      else {
        curLen = 0;
      }
    }
    
    return maxLen;
  }
};


