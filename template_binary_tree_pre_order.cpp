
vector<int> preorderTraversal(TreeNode* root) {
  vector<int> res;
  auto rt = root;
  stack<TreeNode*> st;

  while(rt or st.size()) {
    if(rt) {
      res.emplace_back(rt->val);
      if(rt->right) st.push(rt->right);
      rt = rt->left;
    } 
    else {
      rt = st.top();
      st.pop();
    }
  }
  
  return res;
}
