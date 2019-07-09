class Solution {
public:
  int subarraysWithKDistinct(vector<int>& A, int K) {
    
    function<int(int)> findAtMostK = [&] (int T) {
      
      unordered_map<int, int> hash;
      int left=0, right=0;
      int counter = 0; 

      while(right < A.size()) {
        ++hash[A[right]];

        while(hash.size() > T) {
          --hash[A[left]];
          if(hash[A[left]] == 0)
            hash.erase(A[left]);

          ++left;
        }
        
        // this counts up the number of new subarrays 
        // where the new value A[right] pairs up with
        // all the way up to A[left] subarrays.
        // There is no duplication through the sliding window
        counter += right - left + 1;
        ++right;
      }

      return counter;
    };
    
		// exact K distinct = at most K distinct - at most K-1 distinct
    return findAtMostK(K) - findAtMostK(K-1);
    
  }
};
