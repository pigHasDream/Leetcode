class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
    // This problem the bool and TreeNode* are not equally or symetrically used.
    // bool is only used for the final check.
    // The TreeNode* pointer is more important
    function<pair<bool, TreeNode*>(TreeNode*, TreeNode*, TreeNode*)> 
      doDFS = [&](TreeNode* root, TreeNode* p, TreeNode* q) -> pair<bool, TreeNode*> {
      
      if(root == nullptr) return {false, nullptr};
        
      auto [code_left, ptr_left] = doDFS(root->left, p, q);
      auto [code_right, ptr_right] = doDFS(root->right, p, q);

      if(ptr_left and ptr_right) {
        return {true, root};
      }
      
      if(root == p or root == q) {
        return {ptr_left or ptr_right, root};
      }
      
      return ptr_left ? pair<bool, TreeNode*>{code_left, ptr_left}
                      : pair<bool, TreeNode*>{code_right, ptr_right};
    };
    
    auto [code, ret] = doDFS(root, p, q);
    
    return code ? ret : nullptr;
  }
  
};
