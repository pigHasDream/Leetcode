
class UnionFindSet {
public:
  UnionFindSet(int n):parent_(n) {
    for (int i = 0; i < parents_.size(); ++i)
      parents_[i] = i;
  }
  
  bool Union(int u, int v) {
    int pu = Find(u);
    int pv = Find(v);
    if (pu == pv) 
      return false;
    
    return true;
  }
  
  int Find(int u) {        
    // Compress the path during traversal
    if (u != parents_[u])
      parents_[u] = Find(parents_[u]);        
    return parents_[u];
  }

private:
  vector<int> parents_;
};

