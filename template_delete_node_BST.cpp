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
