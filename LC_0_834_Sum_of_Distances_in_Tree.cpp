class Solution {
  // This problem has many places need to pay attention 
  // 1. convert tree to below graph undirected
  vector<unordered_set<int>> tree_;
  
  // 2. use count_ for recording how many nodes inclusive of a node's subtree
  vector<int> count_;
  
  // 3. the final result
  vector<int> res_;
  
public:
  vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
    tree_.resize(N);
    
    // 4. The initial count of each node's subtree is initialized to 1
    count_.resize(N,1);
    res_.resize(N,0);
    
    // 5. create the tree
    for(const auto& e : edges) {
      tree_[e[0]].insert(e[1]);
      tree_[e[1]].insert(e[0]);
    }
    
    // 6. postOrder dfs is to construct the count_ table
    // AND!! IMPORTANTLY, makes the accurate res_[0] solution, and only this one!!
    // Because we do bottom up accumulation, we do postOrder!
    doPostOrder(0, -1);
    
    // 7. the preOrder traversal is a "DP" procedure
    // It is based on the derived formula:
    // res_[child] = res_[parent] + N - 2*res_[child];
    // Because we do top down, so we do preOrder!
    doPreOrder(0, -1);

    return res_;
  }
  
  // doPostOrder book keep count[] of each subtree node
  // also, res[0] is accurately calculated
  void doPostOrder(int cur, int pre) {
    for(const auto& child : tree_[cur]) {
      // 8. unordered DAG traverseal to avoid repeating!
      // Use parent id and current id to prevent repeating! 
      if(child == pre) continue;
      doPostOrder(child, cur);
      // 9. current node count is the sum of all its children nodes
      count_[cur] += count_[child];
      
      // 10. this actually only becomes valid until the end of the traversl
      // and only res_[0] is valid.
      // Other intermediate res_[i] only refers to the sum dist of subtree of i
      res_[cur] += res_[child] + count_[child];
    }
  }
  
  void doPreOrder(int cur, int pre) {
    for(const auto& child : tree_[cur]) {
      if(child == pre) continue;
      // 11. Apply the formula based on the count (globally) and the parent's res_
      res_[child] = res_[cur] + count_.size() - 2*count_[child];
      doPreOrder(child, cur);
    }
  }
  
};
