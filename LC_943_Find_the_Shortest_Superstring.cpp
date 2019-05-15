// Brute force backtracking

class Solution {
  int bestLen_ = INT_MAX;
  vector<int> soln_ = {};
  vector<vector<int>> combo_ = {};
  
public:
  string shortestSuperstring(vector<string>& A) {
    // combo[i][j] stores i-th then j-th overlap length
    int size = A.size();
    combo_.resize(size, vector<int>(size, 0));
    
    for(int i=0; i<size; ++i) {
      for(int j=0; j<size; ++j) {
        if(i==j) continue;
        int ilen = A[i].size();
        int len = min(ilen, (int)A[j].size());
        for(int k=1; k<=len; ++k) {
          if(A[i].substr(ilen-k) == A[j].substr(0,k)) {
            combo_[i][j] = k;
          }
        }
      }
    }
      
    vector<int> curSoln; 
    doDFS(A, 0, 0, curSoln, 0);
    
    string res;
    for(int i=0; i<size; ++i) {
      if(i==0) res = A[soln_[i]]; 
      else res += A[soln_[i]].substr(combo_[soln_[i-1]][soln_[i]]);
    }
    
    return res;
  }
  
private:
  void doDFS(const vector<string>& A, int prevIdx, int curLen, vector<int>& curSoln, int visit) {
    
    if(curSoln.size() == A.size()) {
      soln_ = curSoln;
      bestLen_ = curLen;
      return;
    }
    
    for(int i=0; i<A.size(); ++i) {
      if(visit & (1<<i)) continue;
      
      int len = curSoln.size() == 0 ? A[i].size() : curLen + A[i].size() - combo_[prevIdx][i];
      if(len > bestLen_) continue;
      
      curSoln.emplace_back(i);
      doDFS(A, i, len, curSoln, visit | (1<<i) );
      curSoln.pop_back();
    }
    
  }
  
};



// Copied from HuaHua DP. 
// Author: Huahua, running time: 20 ms
class Solution {
public:
  string shortestSuperstring(vector<string>& A) {        
    const int n = A.size();
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        g[i][j] = A[j].length();
        for (int k = 1; k <= min(A[i].length(), A[j].length()); ++k)
          if (A[i].substr(A[i].size() - k) == A[j].substr(0, k)) 
            g[i][j] = A[j].length() - k;
      }
    
    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX / 2));
    vector<vector<int>> parent(1 << n, vector<int>(n, -1));
    
    for (int i = 0; i < n; ++i) dp[1 << i][i] = A[i].length();
    
    // the state has 2^n.
    for (int s = 1; s < (1 << n); ++s) {
      for (int j = 0; j < n; ++j) {
        if (!(s & (1 << j))) continue;
        int ps = s & ~(1 << j);
        for (int i = 0; i < n; ++i) {
          if (dp[ps][i] + g[i][j] < dp[s][j]) {
            dp[s][j] = dp[ps][i] + g[i][j];
            parent[s][j] = i;
          }
        }
      }
    }
    
    auto it = min_element(begin(dp.back()), end(dp.back()));
    int j = it - begin(dp.back());
    int s = (1 << n) - 1;
    string ans;
    while (s) {
      int i = parent[s][j];
      if (i < 0) ans = A[j] + ans;
      else ans = A[j].substr(A[j].length() - g[i][j]) + ans;
      s &= ~(1 << j);
      j = i;
    }
    return ans;
  } 
};
