class Solution {
public:
  string alienOrder(vector<string>& words) {
    vector<unordered_set<int>> graph(26);
    
    // This is a special handle when all chars are the same
    // we need to still output valid singleton node
    // so this "special" sink node of index -1 will be used
    for(const auto& w : words)
      for(const auto& c : w)
        graph[c-'a'].emplace(-1);
    
    for(int i=0, j=i+1; j<words.size(); ++i, ++j) {
      for(int idx=0; idx<words[i].size(); ++idx) {
        if(words[i][idx] != words[j][idx]) {
          graph[words[i][idx]-'a'].emplace(words[j][idx]-'a');
          break;
        }
      }
    }
    
    string res;
    // state 0: in the stack visiting
    // state 1: already visited
    vector<int> visit(26,-1);
    
    function<bool(int)> doDFS = [&](const int node) {
      if(visit[node] == 1) return true;
      if(visit[node] == 0) return false;
      
      visit[node] = 0;
      for(const auto& next : graph[node]) {
        // Note this special sink -1 will be skipped!
        if(next == -1) continue;
        if(not doDFS(next)) 
          return false;
      }
      
      visit[node] = 1;
      res += char('a'+node);
      
      return true;
    };
    
    for(int i=0; i<26; ++i) {
      if(graph[i].size()) {
        if(not doDFS(i)) return "";
      }
    }
    
    return string(res.rbegin(), res.rend());
  }
};
