
vector<int> postorderTraversal(TreeNode* root) {
  vector<int> res;
  // {TreeNode*, visit}
  stack<pair<TreeNode*, bool>> st;
  st.push({root, false});
  
  while(st.size()) {
    auto top = st.top();
    st.pop();
    
    // empty node
    if(top.first == nullptr)
      continue;
    
    // has been visited
    if(top.second) {
      res.emplace_back(rt->val);
    }
    else {
      // reversely push the nodes
      // post order: root, right, left
      // in order: right, root, left
      // pre order: right, left, root
      theSt.push({rt, true});
      theSt.push({rt->right, false});
      theSt.push({rt->left, false});
    }
  }
  
  return res;
}
