class Solution {
public:
  int expressiveWords(string S, vector<string>& words) {
    int res = 0;
    
    for(const auto& w : words) {
      if(w.size() > S.size()) continue;
      
      int sL = 0, sR = 0; 
      int wL = 0, wR = 0;
      bool isOK = true;
      
      // 2 pointers.
      // just directly check
      while(wR<w.size()) {
        if(S[sL]!=w[wL]) {
          isOK = false;
          break;
        }
        
        while(sR<S.size() and S[sL] == S[sR]) ++sR;
        while(wR<w.size() and w[wL] == w[wR]) ++wR;
        
        if((sR-sL == wR-wL) or (sR-sL >= 3 and sR-sL > wR-wL)) {
          sL = sR;
          wL = wR;
        }
        else {
          isOK = false;
          break;
        }
      }
      
      if (isOK and sR==S.size() and wR==w.size())
        ++res;
    }
    
    return res;
  }
};
