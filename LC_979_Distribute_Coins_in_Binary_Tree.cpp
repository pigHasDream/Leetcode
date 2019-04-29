
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
