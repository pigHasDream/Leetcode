class Solution {
public:
  int nthUglyNumber(int n) {
    vector<int> ugly;
    ugly.emplace_back(1);
    int i=0, j=0, k=0;
    
    while(--n >0) {
      int theMin = min(ugly[i]*2, 
                       min(ugly[j]*3, ugly[k]*5));
      ugly.emplace_back(theMin);
      
      // Note here we use 3 parallel if-branches instead of
      // if-else.
      // This is to update all the case with same theMin values!!
      // This avoid the duplications!
      if(theMin == ugly[i]*2) ++i;
      if(theMin == ugly[j]*3) ++j;
      if(theMin == ugly[k]*5) ++k;
    }
    
    return ugly.back();
  }
};
