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

class Solution {
public:
  string alienOrder(vector<string>& words) {
    if(words.size() == 1)
      return words.front();
    
    // 2 steps: 
    // 1. Create a directed graph
    // 2. Check for topological order, if there is a loop, return empty
    
    vector<unordered_set<int>> graph(26);
    vector<int> has(26,0);
    
    for(int i=0; i<words.size()-1; ++i) {
      auto w1 = words[i], w2 = words[i+1];
      // below holds all the present chars
      for(const auto& c : w1) has[c-'a'] = 1;
      for(const auto& c : w2) has[c-'a'] = 1;
      
      int k = 0, sz = min(w1.size(), w2.size());
      while(k<sz and w1[k]==w2[k]) ++k;
      if(k<sz) graph[w1[k]-'a'].emplace(w2[k]-'a');
      // if w1 is longer than w2, but they share same prefix, return false
      else if(w1.size() > w2.size()) return "";
    }
    
    vector<int> visit(26, -1);
    string order;
    
    function<bool(int)> doDFS = [&](int idx) -> bool {
      if(visit[idx] == 1) return true;
      if(visit[idx] == 0) return false;
      
      visit[idx] = 0;
      for(const auto& nxt : graph[idx]) {
        if(not doDFS(nxt)) 
          return false;
      }
      visit[idx] = 1;
      
      order = char(idx+'a') + order;
      
      return true;
    };
    
    // This iterates through all present but unvisited nodes!
    for(int i=0; i<26; ++i) {
      if(has[i] and visit[i]==-1)
        if(not doDFS(i)) 
          return "";
    }

    return order;
  }
};
