/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  struct State {
    int upLen_ = 0; 
    int downLen_ = 0; 
  };
  
public:
  int longestConsecutive(TreeNode* root) {
    if(root == nullptr) return 0;
    
    int res = 0;
    function<State(TreeNode*, TreeNode*)> doDFS = [&](TreeNode* root, TreeNode* parent) -> State {
      if(root == nullptr) return {1,1};
      
      auto left = doDFS(root->left, root);
      auto right = doDFS(root->right, root);
      
      res = max(res, max(left.upLen_+right.downLen_-1, right.upLen_+left.downLen_-1));
      
      State newVal;
      
      if(parent) {
        if(parent->val == root->val+1) {
          newVal.upLen_ = max(left.upLen_ + 1, right.upLen_ + 1); 
          newVal.downLen_ = 1;
        }
        else if(parent->val+1 == root->val) {
          newVal.upLen_ = 1;
          newVal.downLen_ = max(left.downLen_ + 1, right.downLen_ + 1); 
        }
        else {
          newVal.upLen_ = 1;
          newVal.downLen_ = 1;
        }
      }
      
      res = max(res, max(newVal.upLen_, newVal.downLen_));
      
      return newVal;
    };
    
    doDFS(root, nullptr);
    
    return res;
  }
  
};
