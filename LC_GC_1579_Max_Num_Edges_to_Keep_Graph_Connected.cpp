lass Solution {
  class UnionFind {
    vector<int> parent_;
    int count_;
    
    public:
      UnionFind(int sz):parent_(sz+1), count_(sz) {
        iota(parent_.begin(), parent_.end(), 0);
      }
    
      int Find(int v) {
        if(parent_[v] != v) {
          parent_[v] = Find(parent_[v]);
        }
        return parent_[v];
      }
    
      bool Union(int v, int u) {
        int pv = Find(v);
        int pu = Find(u);
        if(pu == pv)
          return false;
        
        parent_[pu] = pv;
        --count_;
        return true;
      }
      
      bool canTraverse() const {
        return count_ == 1;
      }
  };
public:
  int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    
    UnionFind uA(n), uB(n);
    int addedEdge = 0;
    sort(edges.begin(), edges.end(), [](const auto& a, const auto& b){
      return a.front() > b.front();
    });
    
    for(const auto& e : edges) {
      if(e.front() == 3) {
        uA.Union(e[1], e[2]);
        addedEdge += uB.Union(e[1], e[2]) ;
      }
      else if(e.front() == 1)
        addedEdge += uA.Union(e[1], e[2]);
      else if(e.front() == 2)
        addedEdge += uB.Union(e[1], e[2]);
    }
    
    return uA.canTraverse() and uB.canTraverse() ?
           edges.size() - addedEdge :
           -1;
  }
};
