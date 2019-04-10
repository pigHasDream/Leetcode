
vector<int> postorderTraversal(TreeNode* root) {
  vector<int> res;
  stack<pair<TreeNode*, bool>> theSt;
  
  theSt.push({root, false});
  
  while(theSt.size()) {
    auto rt = theSt.top().first;
    auto visit = theSt.top().second;
    theSt.pop();
    
    if(rt == nullptr)
      continue;
    
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
