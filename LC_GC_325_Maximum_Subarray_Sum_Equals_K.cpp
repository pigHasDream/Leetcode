class Solution {
public:
  int maxSubArrayLen(vector<int>& nums, int k) {
    vector<int> prefix(nums.size()+1, 0);
    
    for(int i=1; i<=nums.size(); ++i) 
      prefix[i] = prefix[i-1] + nums[i-1];
    
    unordered_map<int,int> hash;
    int res = 0;
    
    for(int i=0; i<prefix.size(); ++i) {
      
      if(hash.count(prefix[i]-k)) {
        res = max(res, i - hash[prefix[i]-k]);
      }
      
      if(hash.count(prefix[i]) == 0)
        hash[prefix[i]] = i;
    }

    return res;
  }
};
