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
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    
    map<int, map<int, set<int>>> sol;
    
    function<void(TreeNode*,int,int)> doDFS = [&](TreeNode* rt, int x, int y) {
      if(rt == nullptr) return;
      
      sol[x][y].emplace(rt->val);
      
      if(rt->left) doDFS(rt->left, x-1, y+1);
      if(rt->right) doDFS(rt->right, x+1, y+1);
    };

    doDFS(root, 0, 0);
    
    vector<vector<int>> res;
    
    for(const auto& xp : sol) {
      vector<int> colRes; 
      for(const auto& yp : xp.second) {
        for(const auto& e : yp.second) {
          colRes.emplace_back(e);
        }
      }
      res.emplace_back(colRes);
    }
    
    return res;
  }
};
