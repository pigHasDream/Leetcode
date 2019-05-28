class Solution {
public:
  bool backspaceCompare(string S, string T) {
    int i=S.size()-1, j=T.size()-1, ci=0, cj=0;
    
    while(i>=0 or j>=0) {
      while(i>=0 and (S[i] == '#' or ci > 0)) {
        S[i] == '#' ? ++ci : --ci;
        --i;
      }
      
      while(j>=0 and (T[j] == '#' or cj > 0)) {
        T[j] == '#' ? ++cj : --cj;
        --j;
      }
      
      if(i<0 or j<0) return i==j;
      
      if(S[i--] != T[j--]) return false;
    }
    
    return i==j;
  }
  
};
