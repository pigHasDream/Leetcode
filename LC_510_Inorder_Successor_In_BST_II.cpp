class Solution {
public:
  Node* inorderSuccessor(Node* node) {
    
    if(node == nullptr) return nullptr;
    
    auto rt = node;
    // has right child
    if(rt->right) {
      rt = rt->right;
      while(rt->left) {
        rt = rt->left;
      }
      return rt;
    }
    
    // need to check parent
    if(rt->parent == nullptr) return nullptr;
    if(rt->parent->left == rt) return rt->parent;
    while(rt->parent and rt->parent->right == rt) {
      rt = rt->parent;
    }
    if(rt->parent) return rt->parent;
    return nullptr;
  }
  
};
