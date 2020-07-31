class Solution {
public:
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    vector<TreeNode*> res;
    unordered_map<string, int> hash;
    
    function<string(TreeNode*)> doDFS = [&](TreeNode* rt) -> string {
      if(rt == nullptr)  
        return "";
      
      string str = to_string(rt->val) + "#" + doDFS(rt->left) + "#" + doDFS(rt->right) + "#";
      
      if(++hash[str] == 2) res.emplace_back(rt);
      
      return str;
    };

    doDFS(root);
    
    return res;
  }
};
