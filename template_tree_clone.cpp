
TreeNode* cloneATree(const TreeNode *root) {
  if(root == nullptr) return nullptr;
  
  TreeNode* newRoot = new TreeNode(root->val);
  
  newRoot->left = cloneATree(root->left);
  newRoot->right = cloneATree(root->right);
  
  return newRoot;
}
