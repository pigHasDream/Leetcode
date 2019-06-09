class Solution {
public:
  string removeDuplicateLetters(string s) {
    
    unordered_map<char, int> hash;
    unordered_set<char> used;
    
    for(const auto &c : s) ++hash[c];
    
    string res;
    for(const auto &c : s) {
      --hash[c];
      
      if(used.count(c)) continue;
      used.emplace(c);
      
      while(res.size() and res.back() > c and hash[res.back()] > 0) {
        used.erase(res.back());
        res.pop_back();
      }
      
      res.push_back(c);
    }

    return res;
  }
};
