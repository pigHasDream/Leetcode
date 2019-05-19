class Solution {
public:
  TreeNode* upsideDownBinaryTree(TreeNode* root) {
    // treat this problem as a singly linked list
    // of left child, plus a small branch in right side
    // eventually just need to reverse the list
    if(root == nullptr) return nullptr;
    
    TreeNode *prev = nullptr, *prevRight = nullptr, *cur = root;
    
    while(cur->left) {
      auto next = cur->left;
      cur->left = prevRight;
      prevRight = cur->right;
      cur->right = prev;
      prev = cur;
      cur = next;
    }
    
    cur->left = prevRight;
    cur->right = prev;
    
    return cur;
  }
  
};
