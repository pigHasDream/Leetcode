class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    
    int sum = 0;
    unordered_map<int,int> mp;
    // This is to accomendate the prefix sum
    // starting from the begining, so we have to 
    // have a 0!
    mp.emplace(0,-1);
    
    for(int i=0; i<nums.size(); ++i) {
      sum += nums[i];
      // k==0, that means the sum must also be 0
      int mod = k==0 ? sum : sum%k;
      // emplace/insert will not overwrite the existing value
      // mp[] this will overwrite!
      mp.emplace(mod, i);
      
      if(i>mp[mod]+1)
        return true;
    }

    return false;
  }
};
