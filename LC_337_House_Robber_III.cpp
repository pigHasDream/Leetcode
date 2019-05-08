class Solution {
public:
  int rob(TreeNode* root) {
    auto res = doDFS(root);
    return max(res.first, res.second);
  }
  
  // first: rob the root and get max
  // second: do not rob the root and get max
  pair<int, int> doDFS(TreeNode* root) {
    if(root == nullptr) return {0,0};
    
    auto left = doDFS(root->left);
    auto right = doDFS(root->right);
    
    return { root->val + left.second + right.second, 
             max(max(left.first + right.second, left.second + right.first),
                 max(left.first + right.first, left.second + right.second)) };
  }
  
  
};
