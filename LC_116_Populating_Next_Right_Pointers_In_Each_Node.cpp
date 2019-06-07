/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
  Node* connect(Node* root) {
    if(root==nullptr) return root;
    
    Node* parent = nullptr;
    Node* layer = root;
    
    // This is a BFS like iteration
    // but we need constant space, so first loop
    // is layer, second level loop is the horizontal nodes
    while(layer->left) {
      parent = layer;
      while(parent) {
        parent->left->next = parent->right;
        if(parent->next)
          parent->right->next = parent->next->left;
        parent = parent->next;
      }
      
      layer = layer->left;
    }
    
    return root;
  }
};
