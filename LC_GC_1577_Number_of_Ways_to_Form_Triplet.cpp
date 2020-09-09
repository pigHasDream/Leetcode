class Solution {
public:
  int numTriplets(vector<int>& nums1, vector<int>& nums2) {
    
    auto count = [](const auto& A, const auto& B) {
      unordered_map<int,int> hash;

      for(const auto& n : B) ++hash[n];

      int res = 0;
      for(const auto& a : A) {
        long p = long(a)*long(a);
        for(auto& [b, cnt] : hash) {
          if(p%b or hash.count(p/b) == 0) continue;
          // if p/b == b, we just need to pick 2 out of the total.
          if(p/b == b) res += cnt*(cnt-1);
          // if p/b != b, we can simply multiply the relation
          else res += cnt * hash[p/b];
        }
      }
      // because we count each twice (looping over the b and p/b)
      // we need to divide by 2
      return res/2;
    };
    
    return count(nums1, nums2) + count(nums2, nums1);
  }
};
