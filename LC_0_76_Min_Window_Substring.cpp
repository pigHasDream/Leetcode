class Solution {
public:
  string minWindow(string s, string t) {
    // General template is to use hashmap with 2 pointers
    // This is a typical way to solve sliding window
    // Use a counter for the condition check
    
    vector<int> theMap(128, 0);
    int size = s.size();
    
    for(const auto& c : t)  
      ++theMap[c];
    
    int minLen=INT_MAX;
    int head = INT_MAX;
    int count = 0;
    int left = 0;
    
    for(int right = 0; right < size; ++right) {
      // Note here is >= 0

      // subtract s[right] still above 0, meaning an effective char.
      // theMap[c] value refers to the count needed from T, but
      // if S has more than needed, keep subtracting theMap[c] will
      // lead to very negative number. Then we will use this nature 
      // to see when moving left boundary towards right, we really still
      // have the valid solution!
      
      if(--theMap[s[right]] >= 0) ++count;
      while(count == t.size()) {
        if(minLen > right - left + 1) {
          minLen = right - left + 1;
          head = left;
        }
        // note here is > 0
        // The magic is hash[c] value can virtually connect
        // left and right!!
        // if hash[c] is way below 0, meaning there are quite a few
        // duplicated c between left and right range, so, it's ok 
        // to keep moving left.
      
        // basically: right bound is to expand for more chances
        // left bound is to test for optimality.

        if(++theMap[s[left]] > 0) --count;
        ++left;
      }
    }
    
    return head == INT_MAX ? "" : s.substr(head, minLen);  
  }

};
