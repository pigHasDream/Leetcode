
// This loop is more efficient although less intuitive
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


// Here is a more intuitive one, but
// will need 2 visits per node.

vector<int> preorderTraversal(TreeNode* root) {
  vector<int> res;
  stack<TreeNode*> st;
  st.push(root);

  while(st.size()) {
    auto top = st.top();
    st.pop();

    if(top == nullptr) continue;

    res.emplace_back(top->val);
    st.push(top->right);
    st.push(top->left);
  }
  
  return res;
}
