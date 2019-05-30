class Solution {
public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    stack<TreeNode*> stc;
    auto rt = root;
    TreeNode* prev = nullptr;
    bool found(false);
    
    while(rt or stc.size()) {
      while(rt) {
        stc.push(rt);
        rt = rt->left;
      }
      
      rt = stc.top(); stc.pop();
      
      // In order traversal
      // It records the bool of found
      // it'll print out in next immediate iteration.

      if(found) return rt;
      
      if(rt->val == p->val) {
        prev = rt;
        found = true; 
      }
      
      rt = rt->right;
    }
    
    return nullptr;
  }
  
};


// ----------------------------------
class Solution {
public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    
    TreeNode* succ = nullptr;
    auto rt = root;
    
    while(rt) {
      if(p->val < rt->val) {
        succ = rt;
        rt = rt->left;
      }
      else {
        rt = rt->right; 
      }
    }
    
    return succ;
  }
  
};
