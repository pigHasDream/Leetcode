class Solution {
public:
  vector<vector<string>> groupStrings(vector<string>& strings) {
    unordered_map<string, vector<string>> mp;
    for(const auto& str : strings) {
      string key;
      for(const auto& c : str) {
        // KEY here is to offset the entire string by first letter!
        // So the relative difference will remain the same for all strings of the same group!
        // One note here is teh z->a, here we need to take an offset by + 26 and modulo 26
        key += to_string((c-str.front() + 26)%26) + ",";
      }
      cout << key << " " << str << endl;
      mp[key].emplace_back(str);
    }
    
    vector<vector<string>> res;
    for(auto& p : mp) {
      auto& vec = p.second;
      sort(vec.begin(), vec.end());
      res.emplace_back(vec);
    }

    return res;
  }
};
