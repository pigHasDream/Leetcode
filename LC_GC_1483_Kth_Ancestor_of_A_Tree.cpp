// Post-order traversal approach.
// Bookkeep all the order of node traversal
// and the level of the tree with all nodes
class TreeAncestor {
  vector<vector<int>> graph_;
  vector<vector<pair<int,int>>> levels_;
  vector<pair<int,int>> nodes_;
  
public:
  TreeAncestor(int n, vector<int>& parent) :
  graph_(n),
  levels_(n),
  nodes_(n) 
  {
    for(int i=1; i<n; ++i) 
      graph_[parent[i]].emplace_back(i);
    
    function<void(int,int,int&)> doPost = [&](int node, int depth, int& id) {
      for(const auto& next : graph_[node]) {
        doPost(next, depth+1, id);
      }
      levels_[depth].emplace_back(id, node);
      nodes_[node] = {depth, id};
      ++id;
    };

    int id = 0;
    doPost(0, 0, id);
  }
    
  int getKthAncestor(int node, int k) {
    const auto& [d, id] = nodes_[node];
    if(k > d) return -1;
    const auto& ps = levels_[d - k];
    return upper_bound(ps.begin(), ps.end(), pair{id, 0})->second;
  }
};

// Binary lift method

class TreeAncestor {
  vector<vector<int>> dp_;
  vector<vector<int>> graph_;
public:
  TreeAncestor(int n, vector<int>& parent) :
  dp_(n, vector<int>()),
  graph_(n, vector<int>())
  {
    // for node 0, it's parent is special, 
    // and we'll check it in the loop
    for(int i=1; i<n; ++i) {
      graph_[parent[i]].emplace_back(i);
    }
    
    function<void(int,vector<int>&)> doDFS = [&] (int node, vector<int>& path) {
      for(int i=1; i<=path.size(); i <<= 1) {
        dp_[node].emplace_back(path[path.size()-i]);
      }
      
      path.emplace_back(node);
      for(const auto& next : graph_[node]) {
        doDFS(next, path);
      }
      path.pop_back();
    };
    
    vector<int> path;
    doDFS(0, path);
  }

  int getKthAncestor(int node, int k) {
    if(k==0) return node;
    if(node == 0 and k > 0) return -1;
    int l = min(31ul - __builtin_clz(k), dp_[node].size() - 1);
    return getKthAncestor(dp_[node][l], k - (1 << l));
  }
  
};

