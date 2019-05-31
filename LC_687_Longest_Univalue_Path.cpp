class Solution {
public:
  int longestUnivaluePath(TreeNode* root) {
    int res = 0;
    getMaxDepth(root, res);
    return res;
  }
  
  // the returned depth must be the length that is 
  // having same value as the root
  // Otherwise, the same value path disconnected.
  // And res already records the longest!
  
  int getMaxDepth(TreeNode* root, int& res) {
    if(root == nullptr) return 0;
    
    auto left = getMaxDepth(root->left, res);
    auto right = getMaxDepth(root->right, res);
    
    int pathLeft=0, pathRight=0;
    if(root->left and root->left->val == root->val) pathLeft = left+1;
    if(root->right and root->right->val == root->val) pathRight = right+1;
    
    res = max(res, pathLeft+pathRight);
    return max(pathLeft, pathRight);
  }
};
