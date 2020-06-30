class Solution {
public:
  bool canArrange(vector<int>& arr, int k) {
    unordered_map<int,int> hash;
    // Below trick to offset the remainder is 
    // the key focus
    for(const auto& e : arr)
      ++hash[(e%k + k)%k];
    
    int cnt_0 = 0;
    for(const auto& [rem, cnt] : hash) {
      if(rem == 0)  cnt_0 += cnt;
      else if(cnt != hash[k-rem]) return false;
    }
    
    return (cnt_0 % 2) ? false : true;
  }
};
