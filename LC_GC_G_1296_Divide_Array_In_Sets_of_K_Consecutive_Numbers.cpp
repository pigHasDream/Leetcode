class Solution {
public:
  bool isPossibleDivide(vector<int>& nums, int k) {
    if(nums.size()%k) return false;
    // <value, count>
    map<int,int> mp;
    
    for(const auto& n : nums) 
      ++mp[n];
    
    while(mp.size()) {
      int start = mp.begin()->first;
      
      for(int i=0; i<k; ++i) {
        if(mp.count(start+i) == 0)
          return false;
        
        --mp[start+i];
        if(mp[start+i] == 0) {
          mp.erase(start+i);
        }
      }
    }
    
    return true;
  }
};
