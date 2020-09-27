/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  int maxPathSum(TreeNode* root) {
    
    int maxVal = INT_MIN;
    
    // return: using root, what's the max => it can be concatenated
    function<int(TreeNode*)> doDFS = [&](TreeNode* rt) {
      if(rt == nullptr) return 0;
      
      auto leftVal = max(doDFS(rt->left), 0);
      auto rightVal = max(doDFS(rt->right), 0);
      
      maxVal = max(maxVal, rt->val + leftVal + rightVal);
      
      return rt->val + max(leftVal, rightVal);
    };

    doDFS(root);
    
    return maxVal;
  }
};
