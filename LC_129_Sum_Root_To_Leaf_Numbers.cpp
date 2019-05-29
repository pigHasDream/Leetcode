class Solution {
public:
  /*
  // -------BFS version-----------
  int sumNumbers(TreeNode* root) {
    if(root == nullptr) return 0;
    queue<pair<TreeNode*, int>> que;
    que.push({root,root->val});
    
    int sum = 0;
    while(que.size()) {
      for(int i=que.size(); i>0; --i) {
        auto top = que.front(); que.pop();
        auto rt = top.first;
        auto sm = top.second;
        if(rt->left == nullptr and rt->right == nullptr) {
          sum += sm;
          continue;
        }
        else {
          if(rt->left) que.push({rt->left, sm*10+rt->left->val});
          if(rt->right) que.push({rt->right, sm*10+rt->right->val});
        }
      }
    }
    
    return sum;
  }
  */
  
  // -------Recursion approach-----------
  int sumNumbers(TreeNode* root) {
    return sumTilHere(root, 0);
  }
  
  int sumTilHere(TreeNode* root, int curSum) {
    if(root == nullptr) return 0;
    
    int sumToH = curSum*10 + root->val;
    
    if(root->left == nullptr and root->right == nullptr)
      return sumToH;
    
    return sumTilHere(root->left, sumToH) + sumTilHere(root->right, sumToH);
  }
};
