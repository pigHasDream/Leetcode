class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> hash(nums.begin(), nums.end());
    
    // Key for this problem is:
    // as long as a number belongs to a group,
    // it'll be ok to just erase it!
    
    int res = 0;
    for(const auto& n : nums) {
      // some numbers are already removed!
      if(hash.count(n) == 0) continue;
      
      int left = n-1;
      int right = n+1;
      while(hash.count(left)) hash.erase(left--);
      while(hash.count(right)) hash.erase(right++);
      
      res = max(res, right-left-1);
    }

    return res;
  }
};
