class Solution {
public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if(root == nullptr)
      return nullptr;
    
    if(root->val > key) {
      root->left = deleteNode(root->left, key);
    }
    else if (root->val < key) {
      root->right = deleteNode(root->right, key);
    }
    else {
      // case 1: leaf node;
      if(root->left == nullptr and root->right == nullptr) {
        delete root;
        root = nullptr;
      }
      // case 2: one child node;
      else if(root->left == nullptr) {
        TreeNode* tmpRoot = root;
        root = root->right; 
        delete tmpRoot;
      }
      else if(root->right == nullptr) {
        TreeNode* tmpRoot = root;
        root = root->left;
        delete tmpRoot;
      }
      // case 3: two children nodes;
      else {
        TreeNode* tmpRoot = findMin(root->right);
        root->val = tmpRoot->val;
        root->right = deleteNode(root->right, root->val);
      }
      
    }
    
    return root;
  }
  
  
  TreeNode* findMin(TreeNode* root) {
    TreeNode* minNode(root);
    while(minNode->left) {
      minNode = minNode->left; 
    }
    return minNode;
  }
  
};
