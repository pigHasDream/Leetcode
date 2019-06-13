class Solution {
public:
  string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> graph;
    function<void(const vector<string>&)> createGraph = [&](const vector<string>& ws) {
      for(const auto& str : ws)
        for(const auto& c : str)
          graph[c].insert(0);

      for(int i=1; i<ws.size(); ++i) {
        auto prev = ws[i-1];
        auto curr = ws[i];
        int idx=0;
        int len=min(prev.size(), curr.size());
        while(idx<len and prev[idx]==curr[idx]) ++idx;
        if(idx<len) 
          graph[prev[idx]].insert(curr[idx]);
      }
    };
    
    createGraph(words);
    
    unordered_map<char, int> status;
    string res;
    function<bool(const char&)> topoSort = [&](const char& cur) {
      if(status.count(cur)) {
        if(status[cur] == 1) 
          return true;
        if(status[cur] == -1) 
          return false;
      }
      
      status[cur] = -1;
      for(const auto& c : graph[cur]) {
        if(c==0) continue;
        if(not topoSort(c)) 
          return false;
      }
      status[cur] = 1;
      
      res.push_back(cur);
      return true;
    };
    
    for(const auto& p : graph)
      if(not topoSort(p.first)) 
        return "";
    
    return string(res.rbegin(), res.rend());
  }
};
