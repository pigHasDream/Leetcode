
vector<int> inorderTraversal(TreeNode* root) {
  vector<int> res;
  auto rt = root;
  stack<TreeNode*> st;

  while(rt or st.size()) {
    while(rt) {
      st.push(rt);
      rt = rt->left;
    }

    rt = st.top();
    st.pop();
    res.emplace_back(rt->val);
    rt = rt->right;
  }

  return res;
}
