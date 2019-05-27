class Solution {
public:
  string rearrangeString(string s, int k) {
    if(k==0) return s;
    
    unordered_map<char, int> hash;
    priority_queue<pair<int, char>> que;
    for(const auto& c : s) ++hash[c];
    for(const auto& h : hash) que.emplace(h.second, h.first);
    
    int len = s.size();
    
    string res;
    while(que.size()) {
      vector<pair<int, char>> tmpHolder;
      // This num is for looping over the k-th
      // or for the last remaining len iterations!
      // Here the len is used for the last batch!
      int num = min(len, k);
      
      for(int i=0; i<num; ++i) {
        // if que is empty but we still have more 
        // letter to insert, that means the remaining 
        // letters are duplicating with those inserted 
        // letters. This is not feasile, return ""
        if(que.empty()) return "";
        
        auto top = que.top();
        que.pop();
        res.push_back(top.second);
        if(--top.first) tmpHolder.emplace_back(top.first, top.second);
        --len;
      }
      
      for(const auto& v : tmpHolder) que.emplace(v);
    }

    return res;
  }
};
