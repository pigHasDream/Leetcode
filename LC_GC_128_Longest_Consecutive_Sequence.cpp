class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    if(nums.empty()) 
      return 0;
    
    unordered_set<int> theSet(nums.begin(), nums.end());
    auto iter = theSet.begin();
		// O(n) time can think of 2-pointers, unordered_set,
    // Kadane's Algorithm etc.
    // From center to expand
    // Also need to remove elements to avoid duplication
    
    int maxLen = 1;
    
    for(const auto& n : nums) {
      if(theSet.count(n) == 0)
        continue;
      
      theSet.erase(n);
      
      int left = n-1;
      while(theSet.count(left)) theSet.erase(left--);
      
      int right = n+1;
      while(theSet.count(right)) theSet.erase(right++);
      
      maxLen = max(maxLen, right-left-1);
    }

    return maxLen;
  }
};
