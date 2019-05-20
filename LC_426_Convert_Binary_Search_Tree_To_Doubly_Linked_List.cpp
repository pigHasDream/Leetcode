class Solution {
public:
  Node* treeToDoublyList(Node* root) {
    if(root == nullptr) return nullptr;
    
    // the pair stores the smallest and largest nodes
    auto ends = doTraverse(root);
    ends.first->left = ends.second;
    ends.second->right = ends.first;
    
    return ends.first;
  }
  
  pair<Node*, Node*> doTraverse(Node* root) {
    
    if(root == nullptr) return {nullptr, nullptr};
    
    auto l = doTraverse(root->left);
    if(l.second) {
      l.second->right = root; 
      root->left = l.second;
    }
    else {
      l = {root, root};
    }
    auto r = doTraverse(root->right);
    if(r.first) {
      root->right = r.first;
      r.first->left = root;
    }
    else {
      r = {root, root};
    }
    
    return {l.first, r.second};
  }
  
};
