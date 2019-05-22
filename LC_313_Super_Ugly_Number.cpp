class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int> res(n,0);
    vector<int> ptr(primes.size(), 0);
    res[0]=1;
    
    // This is essentially a DP.
    // ptr[j] refers to the min ugly number
    // that was lastly times by primes[j]!
    for(int i=1; i<n; ++i) {
      int theMin = INT_MAX;
      for(int j=0; j<primes.size(); ++j)
        theMin = min(theMin, res[ptr[j]]*primes[j]);
      
      for(int k=0; k<primes.size(); ++k) {
        if(theMin == res[ptr[k]]*primes[k]) {
          ++ptr[k];
        }
      }
      res[i] = theMin;
    }

    return res.back();
  }
};
