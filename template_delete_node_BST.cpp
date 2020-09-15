#include <functional>
struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    
    std::function<TreeNode*(TreeNode*)> findMin = [&](TreeNode* rt) ->TreeNode* {
      while(rt->left) {
        rt = rt->left;
      }
      return rt;
    };
    
    if(root == nullptr) return nullptr;
    
    if(key > root->val) {
      root->right = deleteNode(root->right, key);
    }
    else if(key < root->val) {
      root->left = deleteNode(root->left, key);
    }
    else {
      if(root->left == nullptr) {
        auto tmp = root;
        root = root->right;
        delete tmp;
      }
      else if (root->right == nullptr) {
        auto tmp = root;
        root = root->left;
        delete tmp;
      }
      else {
        auto minRight = findMin(root->right);
        root->val = minRight->val;
        root->right = deleteNode(root->right, minRight->val);
      }
    }
    
    return root;
  }
};




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  TreeNode* findMin(TreeNode* rt) {
    while(rt->left) 
      rt = rt->left;
    return rt;
  }
  
public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if(root == nullptr) return nullptr;
    
    if(root->val == key) {
      auto lkid = root->left;
      auto rkid = root->right;
      delete root;
      // root is the node 
      // 0. have both child
      if(lkid and rkid) {
        auto ret = findMin(rkid)->val;
        
        TreeNode* newRoot = new TreeNode(ret);
        newRoot->left = lkid; 
        newRoot->right = deleteNode(rkid, ret);
        return newRoot;
      }
      // 1. no left child
      else if(rkid) return rkid;
      // 2. no right child
      else if(lkid)  return lkid; 
      // 3. no children
      else return nullptr;    
    }
    else if(root->val > key) {
      // in left subtree
      root->left = deleteNode(root->left, key);
    }
    else {
      // in right subtree
      root->right = deleteNode(root->right, key);
    }

    return root;
  }
  
};
