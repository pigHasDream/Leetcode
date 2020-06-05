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
  vector<TreeNode*> generateTrees(int n) {
    if(n==0) return {};
    
    vector<vector<vector<TreeNode*>>> memo(n+1, vector<vector<TreeNode*>>(n+1));
    
    function<vector<TreeNode*>(int,int)> doDFS = [&] (int start, int end) {
      
      vector<TreeNode*> res;
      if(start > end) {
        res.emplace_back(nullptr);
        return res;
      }
      
      if(memo[start][end].size()) return memo[start][end];
        
      if(start == end) {
        res.emplace_back(new TreeNode(start));
      }
      else {
        for(int i=start; i<=end; ++i) {
          auto left = doDFS(start, i-1);
          auto right = doDFS(i+1, end);

          for(auto l : left) {
            for(auto r : right) {
              TreeNode* root = new TreeNode(i);
              root->left = l;
              root->right = r;
              res.emplace_back(root);
            }
          }
        }
      }
      
      memo[start][end] = res;
      return res;
    };

    return doDFS(1,n);
  }
};
