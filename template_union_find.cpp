
class UnionFindSet {
public:
  UnionFindSet(int n): parent_(n, 0), ranks_(n, 0) {
    std::iota(parent_.begin(), parent_.end(), 0);
  }
  
  bool Union(int u, int v) {
    int pu = Find(u);
    int pv = Find(v);
    if (pu == pv) 
      return false;

    // NOTE!!
    // The updates are all on pu or pv!!
    
    if(ranks_[pu] < ranks_[pv]) {
      parent_[pu] = pv;
    }
    else if(ranks_[pu] > ranks_[pv]) {
      parent_[pv] = pu;
    }
    else {
      parent_[pu] = pv;
      ranks_[pv] += 1;
    }
    
    return true;
  }
  
  int Find(int u) {        
    if (u != parents_[u])
      parents_[u] = Find(parents_[u]);        

    return parents_[u];
  }

  int CountUnion() {
    int count = 0;
    for(const auto& i : parent_) 
      if(Find(i) == i) ++count;

    return count;
  }

private:
  vector<int> parents_;
  vector<int> ranks_;
};

