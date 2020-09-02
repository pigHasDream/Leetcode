class Solution {
public:
  int getMaxLen(vector<int>& nums) {
    
    // based on the fact that
    // maxLen only happens in 0 separated segments
    // either from left begin to the last positive number encounterd;
    // or skipping the first negative element and continue to the end.
    
    // Use fast and slow pointer to keep the maxLen for above 2 scenarios
    // Reset when hitting 0.
    
    int len_fast = 0;
    int len_slow = 0;
    int negCount = 0;
    int res = 0;
    
    for(const auto& n : nums) {
      if(n == 0) {
        len_fast = 0;
        len_slow = 0;
        negCount = 0;
      }
      else {
        ++len_fast;
        if(len_slow>0) 
          ++len_slow;
        
        if(negCount == 1 and len_slow == 0) 
          len_slow = 1;
        
        if(n < 0) ++negCount;
        
        if(negCount%2==0)
          res = max(res, len_fast);
        else
          res = max(res, len_slow);
      }
    }
    
    return res;
  }
};
