class Solution {
public:
  int maxPathSum(TreeNode* root) {
    int soFarMax = INT_MIN;
    getMaxUniPath(root, soFarMax);
    
    return soFarMax;
  }
  
	// This does 2 things:
  // 1) return max sum of left to root or right to root path
  // 2) globally maintaining the max sum path
  int getMaxUniPath(TreeNode* root, int &soFarMax) {
    if(root == nullptr) return 0;
    auto left = max(0, getMaxUniPath(root->left, soFarMax));
    auto right = max(0, getMaxUniPath(root->right, soFarMax));
    
    // maintain the best global max sum path
    if(left + right + root->val > soFarMax) 
      soFarMax = left + right + root->val;
    
    // Return the uni direction path to caller
    return max(left, right) + root->val;
  }
};
