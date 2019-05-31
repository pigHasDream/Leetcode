class Solution {
public:
  int diameterOfBinaryTree(TreeNode* root) {
    int maxLen = 0;
    getDepth(root, maxLen);
    
    return maxLen;
  }
  
  int getDepth(TreeNode* root, int& maxLen) {
    if(root == nullptr) return 0;
    
    int left=0, right=0;
    if(root->left) left = getDepth(root->left, maxLen) + 1;
    if(root->right) right = getDepth(root->right, maxLen) + 1; 
     
    maxLen = max(maxLen, left+right);
    
    return max(left, right);
  }
};
