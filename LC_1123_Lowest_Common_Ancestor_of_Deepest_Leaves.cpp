class Solution {
public:
  TreeNode* lcaDeepestLeaves(TreeNode* root) {
    
    // Such tree problem often need to think about several things:
    // 1. is it a preOrder or postOrder or Both? i.e., when to process the returned left/right info?
    // 2. Is there a running max/min for each recursion? if so, either we pass by reference or return it
    // 3. Is there a global max/min value to keep update with? If so, either we globally update it or process it in each iteration.
    function<pair<TreeNode*,int>(TreeNode*, int)> doPostOrder = [&](TreeNode* root, int curDepth) -> pair<TreeNode*, int> {
      if(root == nullptr) return {root, curDepth};
      
      auto left = doPostOrder(root->left, curDepth+1);
      auto right = doPostOrder(root->right, curDepth+1);
      
      auto leftLCA = left.first;
      auto leftDepth = left.second;
      auto rightLCA = right.first;
      auto rightDepth = right.second;
      
      if(leftLCA == nullptr and rightLCA == nullptr) 
        return {root, curDepth+1};
      else if(leftDepth > rightDepth)
        return {leftLCA, leftDepth};
      else if(rightDepth > leftDepth)
        return {rightLCA, rightDepth};
      else
        return {root, leftDepth};
      
    };
    
    auto res = doPostOrder(root, 0);
    
    return res.first;

  }
};
