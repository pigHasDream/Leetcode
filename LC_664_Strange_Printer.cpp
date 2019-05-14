// Also check for LC 546 remove boxes. 
// Almost the same way of defining states.
// Key is the last letter may pair up with
// anyone in the front, so partition based on the 
// same last letter!

class Solution {
  vector<vector<int>> memo_;
public:
  int strangePrinter(string s) {
    // duplicated chars can also be shrinked!
    int n = s.size();
    memo_.resize(n, vector<int>(n, -1));
    
    return doDFS(s, 0, n-1);
  }
  
  int doDFS(const string& s, int left, int right) {
    if(left > right) return 0;
    if(memo_[left][right] != -1) return memo_[left][right];
    
    // Case 1: the [right] is not having any matching letter
    // in left..right-1, then we will need anyway to separately
    // print this last letter!! That's why we have an 1 in the end.
    
    memo_[left][right] = doDFS(s, left, right-1) + 1;
    
    // Case 2: if the [right] has a matching letter with 
    // any one in left..right-1, then we will save this last
    // letter, but it requires the partition point to be the same
    // as the last letter!!
    for(int k=left; k<right; ++k) {
      if(s[right] == s[k]) {
        memo_[left][right] = min(memo_[left][right],  doDFS(s, left, k) + doDFS(s, k+1, right-1));
      }
    }
    
    return memo_[left][right];
  }
  
};
