class Solution {
public:
  int subarraysDivByK(vector<int>& A, int K) {
    int res = 0;
    int prefixSum = 0;
    
    // pair<sum value/module K, count>
    unordered_map<int, int> hash;
    hash[0] = 1;
    for(const auto &n : A) {
      prefixSum += n;
			// negative remainders need to be converted 
			// to positive for the check.
      int remainder = (prefixSum%K+K)%K;
      res += hash[remainder];
      ++hash[remainder];
    }

    return res;
  }
};
