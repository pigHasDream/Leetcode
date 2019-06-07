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
    Node* parent = root;
    Node *child = nullptr;
    Node *childHead = nullptr;
        
    while (parent) {
      while (parent) {
        if (parent->left) {
          if (childHead) {
            child->next = parent->left;
          } else {
            childHead = parent->left;
          }
          child = parent->left;
        }

        if (parent->right) {
          if (childHead) {
            child->next = parent->right;
          } else {
            childHead = parent->right;
          }
          child = parent->right;
        }

        parent = parent->next;
      }

      parent = childHead;
      child = nullptr;
      childHead = nullptr;
    }
    
    return root;
  }
};
