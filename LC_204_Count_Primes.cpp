class Solution {
public:
  int countPrimes(int n) {
    if(n<2) return 0;
    vector<bool> vec(n, true);
    vec[0] = false, vec[1] = false;
    
    // sqrt(n) removes the reflection case duplications
    // like 12 = 2x6 = 3x4 = 4x3 = 6x2
    for(int i=2; i<sqrt(n); ++i) {
      if(vec[i]) {
        // we can directly start from i^2 as the 
        // smaller multiples less than i has been 
        // covered by earlier primes!!
        for(int j=i*i; j<n; j+=i) {
          vec[j] = false;
        }
      }
    }
    
    return count(vec.begin(), vec.end(), true);
  }
};
