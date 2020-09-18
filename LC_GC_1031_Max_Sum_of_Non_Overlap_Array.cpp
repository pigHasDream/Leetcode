class Solution {
public:
  int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
    int sz = A.size();
    if(sz < L+M) return 0;
    
    vector<int> sums(sz+1, 0);
    for(int i=1; i<=sz; ++i)
      sums[i] = sums[i-1] + A[i-1];
    
    int Lmax = 0, Mmax = 0;
    int res = 0;
    
    // Key is to keep track of to j-th position,
    // what is the max L and M segment ?
    // what is the max M and L segment ?
    for(int i=L+M; i<=sz; ++i) {
      Lmax = max(Lmax, sums[i-M] - sums[i-L-M]);
      Mmax = max(Mmax, sums[i-L] - sums[i-L-M]);
      
      int L_M_sum = sums[i]-sums[i-M];
      int M_L_sum = sums[i]-sums[i-L];
      
      res = max({res, Lmax+L_M_sum, Mmax+M_L_sum});
    }

    return res;
  }
};
