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


// Left and right subtree must be one perfect and another completed.
// So, one of the two subtrees must have lgn run time (perfect), and 
// only one of the two subtrees will have a recursion. 
// Expanding this relation, we eventually get lgn*lgn
//  
// T(n) = T(n/2) + c1 lgn
//      = T(n/4) + c1 lgn + c2 (lgn - 1)
//      = ...
//      = T(1) + c [lgn + (lgn-1) + (lgn-2) + ... + 1]
//      = O(lgn*lgn)   
