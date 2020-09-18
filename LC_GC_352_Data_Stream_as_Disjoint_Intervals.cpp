class SummaryRanges {
  map<int,int> parent_;
  map<int, pair<int,int>> range_;
  
  int findParent(int v) {
    if(parent_.count(v) == 0) return -1;
    if(parent_[v] != v) {
      parent_[v] = findParent(parent_[v]);
    }
    return parent_[v];
  }
  
  void addVal(int v) {
    parent_[v] = v;
    range_[v] = {v, v};
  }
  
  bool unionTwo(int v, int u) {
    auto pv = findParent(v);
    auto pu = findParent(u);
    
    if(pv == -1 or pu == -1)
      return false;
    
    if(pv == pu) 
      return false;
    
    parent_[pv] = pu;
    range_[pu].first = min(range_[pu].first, range_[pv].first);
    range_[pu].second = max(range_[pu].second, range_[pv].second);
    range_.erase(pv);
    
    return true;
  }
  
public:
  /** Initialize your data structure here. */
  SummaryRanges() {
  }

  void addNum(int val) {
    auto parent = findParent(val);
    if(parent == -1) {
      addVal(val);
      unionTwo(val, val-1);
      unionTwo(val, val+1);
    }
  }

  vector<vector<int>> getIntervals() {
    vector<vector<int>> res;
    for(const auto& intv : range_)
      res.emplace_back(vector<int>{intv.second.first, intv.second.second});

    return res;
  }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
