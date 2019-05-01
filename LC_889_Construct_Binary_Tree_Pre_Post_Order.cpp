class Solution {
public:
  using VI = vector<int>::iterator;
  
  TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
    return doRecursion(pre, post, begin(pre), end(pre), begin(post), end(post));
  }
  
  TreeNode* doRecursion(vector<int> pre, vector<int> post, VI pre_s, VI pre_e, VI post_s, VI post_e) {
    if(pre_s == pre_e)
      return nullptr;
    
    auto root = new TreeNode(*pre_s);
    ++pre_s;
    --post_e;
    
    if(pre_s == pre_e) return root;
    
    auto post_m = next(find(post_s, post_e, *pre_s));
    auto pre_m = pre_s + (post_m - post_s);
    
    root->left = doRecursion(pre, post, pre_s, pre_m, post_s, post_m);
    root->right = doRecursion(pre, post, pre_m, pre_e, post_m, post_e);
   
    return root;
  }
  
};
