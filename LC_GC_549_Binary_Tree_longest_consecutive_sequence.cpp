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
public:
  int longestConsecutive(TreeNode* root) {
    
    int maxLen = 0;
    
    // pair<increase, decrease> using the given node
    function<pair<int,int>(TreeNode*)> doDFS = 
      [&] (TreeNode* rt) -> pair<int,int> {
      if(rt == nullptr) return {0,0};
      
      int leftIncr = 0, leftDecr = 0, rightIncr = 0, rightDecr = 0;
      
      if(rt->left) {
        auto [i, d] = doDFS(rt->left);
        leftIncr = i;
        leftDecr = d;
      }
      
      if(rt->right) {
        auto [i, d] = doDFS(rt->right);
        rightIncr = i;
        rightDecr = d;
      }
      
      // This is post order traversal only for child->parent->child case!
      if(rt->left and rt->right) {
        if(rt->left->val == rt->val+1 and rt->right->val + 1 == rt->val) {
          maxLen = max(maxLen, leftDecr + rightIncr + 1);
        }
        else if(rt->left->val + 1 == rt->val and rt->right->val == rt->val + 1) {
          maxLen = max(maxLen, leftIncr + rightDecr + 1);
        }
      }
      
      // get one sided largest length for return
      int retIncr = 1, retDecr = 1;
      
      if(rt->left) {
        if(rt->left->val == 1 + rt->val) 
          retDecr = max(retDecr, leftDecr+1);
        else if (rt->left->val + 1 == rt->val)
          retIncr = max(retIncr, leftIncr+1);
      }
        
      if(rt->right) {
        if(rt->right->val == 1 + rt->val) 
          retDecr = max(retDecr, rightDecr+1);
        else if (rt->right->val +1 == rt->val)
          retIncr = max(retIncr, rightIncr+1);
      }
      
      maxLen = max(maxLen, max(retIncr, retDecr));
      
      return {retIncr, retDecr};
      
    };

    doDFS(root);
    
    return maxLen;
  }
};
