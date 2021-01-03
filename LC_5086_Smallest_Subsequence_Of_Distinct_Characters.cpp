#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
  std::string smallestSubsequence(std::string text) {
    std::unordered_map<char, int> hash;
    std::unordered_set<char> use;
    
    for(const auto &c : text) ++hash[c];
    
    std::string res;
    for(const auto &c : text) {
      --hash[c];
      
      if(use.count(c)) continue;
      use.emplace(c);
      
      while(res.size() and res.back() > c and hash[res.back()] > 0) {
        use.erase(res.back());
        res.pop_back();
      }
      
      res.push_back(c);
    }
    
    return res;
  }
};
