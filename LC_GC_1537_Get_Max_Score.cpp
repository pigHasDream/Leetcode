class Solution {
  constexpr static int mod_ = 1e9+7;
public:
  int maxSum(vector<int>& nums1, vector<int>& nums2) {
    int res = 0;
    int ptc = 0; int ptp = 0;
    long retc = 0; long retp = 0;
    unordered_set<int> setc(nums1.begin(), nums1.end());
    unordered_set<int> setp(nums2.begin(), nums2.end());
    vector<int>& vecc(nums1);
    vector<int>& vecp(nums2);
    bool visited = false;
    
    while(ptc < vecc.size()) {
      auto num = vecc[ptc];
      if(setp.count(num)) {
        if(visited) {
          res = (res%mod_ + (max(retc, retp)%mod_ + num%mod_)%mod_)%mod_;
          retc = 0;
          retp = 0;
          ++ptc;
          ++ptp;
          visited = false;
        }
        else {
          swap(vecc, vecp);
          swap(setc, setp);
          swap(retc, retp);
          swap(ptc, ptp);
          visited = true;
        }
      }
      else {
        retc += num;
        ++ptc;
      }
    }
    
    while(ptp < vecp.size()) {
      retp += vecp[ptp];
      ++ptp;
    }

    res = (res%mod_ + max(retc, retp)%mod_)%mod_;
    
    return res%mod_;
  }
};
