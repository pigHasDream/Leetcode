class Solution {
public:
  int lengthOfLongestSubstringKDistinct(string s, int k) {
    const int sz = s.size();
    unordered_map<char, int> uniq;
    int res = 0, start = 0;
    
    for(int end=0; end<sz; ++end) {
      // increase for corresponding value
      ++uniq[s[end]];
      
      // if total uniq char is more than k, need to move start pointer
      while(uniq.size() > k) {
        // as we move right-wards the start pointer, 
        // we need to reduce s[start] count.
        // when the count reduces to 0, 
        // we need to kick out the element hence the uniq has 2 keys only.
        if(--uniq[s[start]] == 0)  uniq.erase(s[start]);
        ++start;
      }
      
      res = max(res, end-start+1);
    }
    return res;
  }
};
