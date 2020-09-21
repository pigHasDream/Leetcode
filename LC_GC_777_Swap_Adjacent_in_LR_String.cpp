class Solution {
public:
  bool canTransform(string start, string end) {
    if(start.size() != end.size()) return false;
    
    int Ls = -1, Rs = -1, Le = -1, Re = -1;
    int i = 0, j = 0;
    int lcs = 0, rcs = 0, lce = 0, rce = 0;
    
    while(i<start.size() or j<end.size()) {
      while(i<start.size() and start[i]=='X') ++i;
      while(j<end.size() and end[j]=='X') ++j;
      
      if(i<start.size()) {
        if(start[i]=='L') {
          Ls = i; ++lcs;
        }
        else if(start[i]=='R') {
          Rs = i; ++rcs;
        }
      }
      
      if(j<start.size()) {
        if(end[j]=='L') {
          Le = j; ++lce;
        }
        else if(end[j]=='R') {
          Re = j; ++rce;
        }
      }
      
      if(Ls < Le or Rs > Re) return false;
      ++i, ++j;
    }
    
    return lcs == lce and rcs == rce;
  }
};
