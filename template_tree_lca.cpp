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
  
  auto left = LCA(root->left, p, q);
  auto right = LCA(root->right, p, q);
  
  return (left and right) ? root 
                          : left ? left : right;
}


// -------------- General LCA when p and q are not guaranteed in the Tree --------------------
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

	TreeNode* res = nullptr;

	function<pair<bool, bool>(TreeNode*, TreeNode*, TreeNode*)> 
		doDFS = [&](TreeNode* root, TreeNode* p, TreeNode* q) -> pair<bool, bool> {

			if(root == nullptr) return {false, false};

			int pFound = false, qFound = false;
			if(root == p) pFound = true;
			if(root == q) qFound = true;

			auto left = doDFS(root->left, p, q);
			auto right = doDFS(root->right, p, q);

			pFound = pFound or left.first or right.first;
			qFound = qFound or left.second or right.second;

			if(pFound and qFound and res == nullptr)
				res = root; 

			return {pFound, qFound};
		};

	doDFS(root, p, q);

	return res;
}

// -------------- General LCA when p and q are not guaranteed in the Tree --------------------
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  
  // This problem the bool and TreeNode* are not equally or symetrically used.
  // bool is only used for the final check.
  // The TreeNode* pointer is more important
  function<pair<bool, TreeNode*>(TreeNode*, TreeNode*, TreeNode*)> 
    doDFS = [&](TreeNode* root, TreeNode* p, TreeNode* q) -> pair<bool, TreeNode*> {
    
    if(root == nullptr) return {false, nullptr};
      
    auto [code_left, ptr_left] = doDFS(root->left, p, q);
    auto [code_right, ptr_right] = doDFS(root->right, p, q);

    if(ptr_left and ptr_right) {
      return {true, root};
    }
    
    if(root == p or root == q) {
      return {ptr_left or ptr_right, root};
    }
    
    return ptr_left ? pair<bool, TreeNode*>{code_left, ptr_left}
                    : pair<bool, TreeNode*>{code_right, ptr_right};
  };
  
  auto [code, ret] = doDFS(root, p, q);
  
  return code ? ret : nullptr;
}
