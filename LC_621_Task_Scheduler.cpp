class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> hash;
    priority_queue<pair<int,char>> que;
    for(const auto& t : tasks) ++hash[t];
    for(const auto& h : hash) que.emplace(h.second, h.first);
    
    int len = tasks.size();
    int res = 0;
    char prev;
    while(que.size()) {
      vector<pair<int,char>> tmpHolder;
      
      for(int i=0; i<=n; ++i) {
        if(que.empty()) {
          if(tmpHolder.size()) {
            prev = '-';
            ++res;
            continue;
          }
          else break;
        }
        auto top = que.top(); que.pop();
        prev = top.second;
        if(--top.first) tmpHolder.emplace_back(top.first, top.second);
        ++res;
      }
      
      for(const auto& v : tmpHolder) que.emplace(v);
    }
    
    return res;
  }
};
