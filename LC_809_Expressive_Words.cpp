class Solution {
public:
  int expressiveWords(string S, vector<string>& words) {

    int res = 0;
    for(const auto w : words)
      if(check(S, w)) ++res;
    
    return res;
  }
  
  bool check(const string& S, const string& w) {
    
    int m = w.size(), n = S.size(); 
    int i = 0, j = 0;
    for(int i2=0, j2=0; i<n and j<m; i=i2, j=j2) {
      if(S[i] != w[j]) return false;
      
      while(i2 < n and S[i2] == S[i]) ++i2;
      while(j2 < m and w[j2] == w[j]) ++j2;
      
      if(i2-i != j2-j and (i2-i) < max(3, j2-j)) return false;
    }
    
    return i==n and j==m;
  }
    
};
