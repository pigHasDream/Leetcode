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
public:
  int pathSum(TreeNode* root, int sum) {
    if(root == nullptr) return 0;

    unordered_map<int,int> hash;
    hash.emplace(0,1);
    
    int res = 0;
    
    function<void(TreeNode*, int)> doDFS = [&](TreeNode* rt, int curSum) {
      if(rt == nullptr) return;
      
      int newSum = curSum + rt->val;
      
      if(hash.count(newSum - sum)){
        res += hash[newSum - sum];
      }
      
      ++hash[newSum];
      
      doDFS(rt->left, newSum);
      doDFS(rt->right, newSum);
      
      --hash[newSum];
    };

    doDFS(root, 0);
    
    return res;
  }
};
