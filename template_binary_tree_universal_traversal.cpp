
vector<int> postorderTraversal(TreeNode* root) {
  vector<int> res;
  // {TreeNode*, visit}
  stack<pair<TreeNode*, bool>> st;
  st.push({root, false});
  
  while(st.size()) {
    auto rt = st.top().first;
    auto visit = st.top().second;
    st.pop();
        
    if(rt == nullptr) continue;
    
    if(visit) {
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
