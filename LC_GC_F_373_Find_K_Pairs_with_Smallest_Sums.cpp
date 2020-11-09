class Solution {
public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    const int sz1 = nums1.size();
    const int sz2 = nums2.size();
    if(sz1 == 0 or sz2 == 0 or k<0)
      return {};
    
    // Note how I define the customized std::set!
    // It has to fully list all scenarios to serve the duplicaion check purpose
    // It also has to define the sum compares for the sorting purpose!
    auto cmp = [&](const pair<int,int>& a, const pair<int,int>& b) {
      int sum1 = nums1[a.first] + nums2[a.second];
      int sum2 = nums1[b.first] + nums2[b.second];
      if(sum1 == sum2) {
        if(a.first == b.first)
          return a.second < b.second;
        return a.first < b.first;
      }
      return sum1 < sum2;
    };
    
    set<pair<int,int>, decltype(cmp)> theSet(cmp);
    
    theSet.emplace(0,0);
    vector<vector<int>> res;
    
    while(k-- >0 and theSet.size()) {
      auto [idx1, idx2] = *theSet.begin();
      theSet.erase(theSet.begin());
      
      res.emplace_back(vector<int>{nums1[idx1], nums2[idx2]});
      
      if(idx1<sz1-1) {
        theSet.emplace(idx1+1, idx2);
      }
      if(idx2<sz2-1) {
        theSet.emplace(idx1, idx2+1);
      }
    }
    
    return res;
  }
};
