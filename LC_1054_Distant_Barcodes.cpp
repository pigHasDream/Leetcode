class Solution {
public:
  vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    unordered_map<int,int> hash;
    priority_queue<pair<int,int>> que;
    
    for(const auto& bar : barcodes) ++hash[bar];
    
    for(const auto& elem : hash) que.emplace(elem.second, elem.first);
    
    vector<int> res;
    while(que.size()) {
      auto top = que.top();
      que.pop();
      
      // greedily insert the highest freq one
      if(res.empty() or res.back() != top.second) {
        res.emplace_back(top.second);
        --top.first;
        if(top.first) que.emplace(top.first, top.second);
      }
      // if the highest freq one is the same as prev insertion
      // try a different one
      else {
        auto top2 = que.top();
        que.pop();
        que.emplace(top);
        res.emplace_back(top2.second);
        --top2.first;
        if(top2.first) que.emplace(top2.first, top2.second);
      }
    }

    return res;
  }
};
