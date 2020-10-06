class Solution {
public:
  int distributeCoins(TreeNode* root) {
    
    int res = 0;
    
    function<int(TreeNode*)> doDFS
      = [&](TreeNode* rt) -> int {
      
      if(rt == nullptr) return 0;
      
      auto leftExtra = doDFS(rt->left);
      auto rightExtra = doDFS(rt->right);
      
      int retExtra = rt->val - 1 + leftExtra + rightExtra;
      
      res += abs(leftExtra) + abs(rightExtra);
        
      return retExtra;
    };
    
    doDFS(root);
    
    return res;
  }
};



class Solution {
  int res_ = 0;
public:
  int distributeCoins(TreeNode* root) {
    
    if(root == nullptr) return 0;
    doDFS(root);
    
    return res_;
  }
  
  // Return the pair {node count, coin count}
  // moves will be the coin and node difference abs

  pair<int, int> doDFS(TreeNode* root) {
    if(root==nullptr) return {0,0};
    
    auto left = doDFS(root->left);
    auto right = doDFS(root->right);
    
    res_ += abs(left.first - left.second) + abs(right.first - right.second);
    
    return {left.first + right.first + 1, left.second + right.second + root->val};
  }
  
};
