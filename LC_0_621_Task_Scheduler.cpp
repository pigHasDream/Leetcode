class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    vector<int> hash(26,0);
    for(const auto& t : tasks)
      ++hash[t-'A'];
    
    priority_queue<int> pq;
    for(const auto& h : hash)
      if(h>0) pq.emplace(h);
    
    int res = 0;
    int cycle = n+1;  
    while(pq.size()) {
      
      vector<int> tmp;
      int slot = 0;
      
      for(int i=0; i<cycle; ++i) {
        if(pq.empty()) break;
        
        auto top = pq.top(); pq.pop();
        ++slot;
        
        if(top>1) 
          tmp.emplace_back(top-1);
      }
      
      for(const auto& t : tmp)
        pq.emplace(t);
      
      res += pq.size() ? cycle : slot;
    }
    
    return res;
  }
};
