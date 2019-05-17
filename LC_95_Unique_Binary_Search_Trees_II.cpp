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
  vector<TreeNode*> generateTrees(int n) {
    if(n==0)
      return {};
    
    return generateTree(1, n);
  }
  
  vector<TreeNode*> generateTree(int start, int end) {
    
    vector<TreeNode*> res;
    
    if(start > end) {
      res.emplace_back(nullptr);
    }
    else if(start == end) {
      res.emplace_back(new TreeNode(start));
      return res;
    }
    
    for(int i=start; i<=end; ++i) {
      auto left = generateTree(start, i-1);
      auto right = generateTree(i+1, end);
      
      for(auto l : left)
        for(auto r : right) {
          TreeNode* newNode = new TreeNode(i);
          newNode->left = l;
          newNode->right = r;
          res.emplace_back(newNode);
        }
    }
    
    return res;
    
  }
  
};
