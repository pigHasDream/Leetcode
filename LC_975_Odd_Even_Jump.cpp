class Solution {
public:
  int oddEvenJumps(vector<int>& A) {
    int n=A.size();
    vector<bool> lower(n, false);
    vector<bool> higher(n, false);
    
    lower[n-1] = true;
    higher[n-1] = true;
    map<int, int> theMap;
    theMap[A[n-1]] = n-1;
    
    // ret already has the n-1 by default
    int ret = 1;
    for(int i=n-2; i>=0; --i) {
      // This lower_ upper_ bound is very tricky!
      auto hi = theMap.lower_bound(A[i]);
      auto lo = theMap.upper_bound(A[i]);
      if(hi != theMap.end()) higher[i] = lower[hi->second];
      if(lo != theMap.begin()) lower[i] = higher[prev(lo)->second];
      if(higher[i]) ++ret;
      theMap[A[i]] = i;
    }
    
    return ret;
  }
};
