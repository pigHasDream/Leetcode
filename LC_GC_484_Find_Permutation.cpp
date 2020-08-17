class Solution {
public:
  vector<int> findPermutation(string s) {
    vector<int> res;
    stack<int> stc;

    // key is to realize stack can elegantly reverse
    // the order. 
    // But need to carefully take care the edge cases
    int idx = 1;
    for(const auto& c : s) {
      if(c == 'I') {
        res.emplace_back(idx);
        while(stc.size()) {
          res.emplace_back(stc.top());
          stc.pop();
        }
      }
      else {
        stc.emplace(idx);
      }
      ++idx;
    }
    
    // still need to push the last element
    // bacause it creates an additional pair
    stc.emplace(idx);
    
    while(stc.size()) {
      res.emplace_back(stc.top());
      stc.pop();
    }
      
    return res;
  }
};
