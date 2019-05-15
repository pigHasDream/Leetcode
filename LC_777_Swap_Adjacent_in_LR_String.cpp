class Solution {
public:
  bool canTransform(string start, string end) {
    int nstart = start.size();
    int nend = end.size();
    
    if(nstart != nend) return false;
    
    string reducedS, reducedE;
    
    for(int i=0; i<nstart; ++i) {
      if(start[i]!='X') reducedS += start[i];
      if(end[i]!='X') reducedE += end[i];
    }
    
    if(reducedS != reducedE) return false;
    
    int i=0, j=0;

    // Below iterates 2 strings and skips all 'X'
    // then compare the L and R letter in both strings
    // mandating the corresponding orders.
    while(i<nstart and j<nend) {
      while(i<nstart and start[i] == 'X') ++i;
      while(j<nend and end[j] == 'X') ++j;
      
      if(i==nstart or j==nend) break;
      if(start[i] == 'R' and i>j) return false;
      if(start[i] == 'L' and i<j) return false; 
      ++i;
      ++j;
    }
    
    return true;

  }
};
