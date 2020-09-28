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
  int maxPathSum(TreeNode* root) {
    
    int maxVal = INT_MIN;
    
    // return: using root, what's the max => it can be concatenated
    function<int(TreeNode*)> doDFS = [&](TreeNode* rt) {
      if(rt == nullptr) return 0;
      
      auto leftVal = max(doDFS(rt->left), 0);
      auto rightVal = max(doDFS(rt->right), 0);
      
      maxVal = max(maxVal, rt->val + leftVal + rightVal);
      
      return rt->val + max(leftVal, rightVal);
    };

    doDFS(root);
    
    return maxVal;
  }
};


// Below is the less efficient method, come up by myself.
class Solution {
public:
  int maxPathSum(TreeNode* root) {
    
    int maxVal = INT_MIN;
    
    // return: using root, what's the max => it can be concatenated
    function<pair<bool,int>(TreeNode*)> doDFS = [&](TreeNode* rt) -> pair<bool,int> {
      if(rt == nullptr) return {false, 0};
      
      auto [leftRet, leftVal] = doDFS(rt->left);
      auto [rightRet, rightVal] = doDFS(rt->right);
      
      maxVal = max(maxVal, rt->val);
      
      if(leftRet and rightRet) {
        maxVal = max({maxVal, leftVal, rightVal,
                      leftVal+rt->val, rightVal+rt->val,
                      leftVal+rt->val+rightVal});
        return {true, max({rt->val, leftVal+rt->val, rightVal+rt->val})};
      }
      else if(leftRet) {
        maxVal = max({maxVal, leftVal, leftVal+rt->val});
        return {true, max(rt->val, leftVal+rt->val)};
      }
      else if(rightRet) {
        maxVal = max({maxVal, rightVal, rightVal+rt->val});
        return {true, max(rt->val, rightVal+rt->val)};
      }
                          
      return {true, rt->val};
    };

    doDFS(root);
    
    return maxVal;
  }
};
