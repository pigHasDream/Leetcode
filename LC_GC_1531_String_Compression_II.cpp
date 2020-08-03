int dp[101][101][27][101];

class Solution {
public:
  int getLengthOfOptimalCompression(string s, int K) {
    memset(dp, -1, sizeof dp);
    
    function<int(int,int,int,int)> doDFS = 
      [&](int idx, int k, int last, int len) {
      
      if(k < 0) return INT_MAX/2;
      if(idx + k >= s.size()) return 0;
      
      int& ans = dp[idx][k][last][len];
      if(ans != -1) return ans;
      
      if(s[idx] - 'a' == last) {
        int carry = (len == 1 or len == 9 or len == 99);
        ans = carry + doDFS(idx+1, k, last, len+1);
      }
      else {
        ans = min(doDFS(idx+1, k-1, last, len), // delete
                  1 + doDFS(idx+1, k, s[idx]-'a', 1)); // keep
      }
      
      return ans;
    };
    
    return doDFS(0, K, 26, 0);
  }
};
