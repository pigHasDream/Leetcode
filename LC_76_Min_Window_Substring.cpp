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
      if(--theMap[s[right]] >= 0) ++count;
      while(count == t.size()) {
        if(minLen > right - left + 1) {
          minLen = right - left + 1;
          head = left;
        }
        if(++theMap[s[left]] > 0) --count;
        ++left;
      }
    }
    
    return head == INT_MAX ? "" : s.substr(head, minLen);  
  }

};
