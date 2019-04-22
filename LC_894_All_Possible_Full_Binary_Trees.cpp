class Solution {
public:
  Solution() : forest_(30, vector<TreeNode*>(0)) {}
  
  vector<TreeNode*> allPossibleFBT(int N) {
    
    if(N%2 == 0) return {};
    
    if(forest_[N].size())
      return forest_[N];
    
    vector<TreeNode*> res;

    // the current root, count towards 1
    if(N == 1) {
      TreeNode* root = new TreeNode(0);
      res.emplace_back(root); 
    }
    
    for(int i=2; i<=N; i+= 2) {

      auto leftForest = allPossibleFBT(i-1);
      auto rightForest = allPossibleFBT(N-i);

      for(auto left : leftForest) {
        for(auto right : rightForest) {
          TreeNode* rt = new TreeNode(0);
          rt->left = left;
          rt->right = right;
          res.emplace_back(rt);
        }
      }
    }
    
    forest_[N] = res;
    return res;
  }
  
private:
  vector<vector<TreeNode*>> forest_;
  
};
