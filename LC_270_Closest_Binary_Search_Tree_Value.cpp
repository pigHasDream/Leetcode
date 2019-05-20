class Solution {
public:
  int closestValue(TreeNode* root, double target) {
    
    double rootVal = root->val;
    
    if(target > rootVal and root->right) {
      double r = closestValue(root->right, target);
      return abs(r-target) < abs(rootVal-target) ? int(r) : int(rootVal);
    }
    
    if(target < rootVal and root->left) {
      double l = closestValue(root->left, target);
      return abs(l-target) < abs(rootVal-target) ? int(l) : int(rootVal);
    }
    
    return root->val;
  }
  
};
