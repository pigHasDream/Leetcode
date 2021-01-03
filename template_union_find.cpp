#include <numeric>
#include <vector>
#include <string>

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
    /* if we assign -1 to each of the parent value,
     * then in below when parent_[u] == -1, we should
     * return u instead of -1. So that they can be compared.
     * */
    if (u != parent_[u])
      parent_[u] = Find(parent_[u]);        

    return parent_[u];
  }

  int CountUnion() {
    int count = 0;
    for(const auto& i : parent_) 
      if(Find(i) == i) ++count;

    return count;
  }

private:
  std::vector<int> parent_;
  std::vector<int> ranks_;
};

