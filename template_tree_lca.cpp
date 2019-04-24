// ------------- BST LCA -----------------
TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
  
  // check two children branches
  // or return the current root
  
  if (root->val > q->val and root->val > p->val) {
    return LCA(root->left, p, q);
  }
  else if (root->val < q->val and root->val < p->val) {
    return LCA(root->right, p, q);
  }

  return root;
}


// ----------- General LCA -------------
TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {

  // ASSUME: all values of nodes are unique!	
  // termination is nullptr (leaf) or root is same as
  // either one of the 2 targets.

  if(root == nullptr or root == p or root == q) 
    return root;
  
  auto left = lowestCommonAncestor(root->left, p, q);
  auto right = lowestCommonAncestor(root->right, p, q);
  
  return (left and right) ? root 
                          : left ? left : right;
}


