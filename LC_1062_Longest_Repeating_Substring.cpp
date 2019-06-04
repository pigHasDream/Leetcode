class Solution {
public:
  int longestRepeatingSubstring(string S) {
    int size = S.size();
    if(size == 0) return 0;
    
    auto checkValid = [size, S] (int len) -> bool {
      unordered_set<string> hash;
      for(int i=0; i<=size-len; ++i) {
        auto sub = S.substr(i, len);
        if(hash.count(sub)) return true;
        hash.emplace(sub);
      }
      return false; 
    };
    
    // using binary search because, 
    // if smaller length is not valid, longer won't
    // This counts towards a monotonic relation!
    
    int left = 1, right = size; 
    while(left < right) {
      int mid = left + (right-left)/2;
      
      if(checkValid(mid))
        left = mid+1;     
      else 
        right = mid;
    }
    
    return left-1;
  }
  
};
