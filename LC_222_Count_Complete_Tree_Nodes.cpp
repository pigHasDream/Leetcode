class Solution {
public:
  int countNodes(TreeNode* root) {
    if(root == nullptr)
      return 0;
    
    auto left = root;
    auto right = root;
    
    int ll = 0, lr = 0;
    while(left) {
      ++ll;
      left = left->left;
    }
    
    while(right) {
      ++lr;
      right = right->right;
    }
    
    if(lr == ll) return (1<<ll)-1;
      
    return 1 + countNodes(root->left) + countNodes(root->right);

  }
};
