/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
  BSTIterator(TreeNode* root) {
    while(root) {
      stc_.emplace(root);
      root = root->left;
    }
  }

  /** @return the next smallest number */
  int next() {
    auto top = stc_.top(); stc_.pop();
    TreeNode* rt = top->right;
    while(rt) {
      stc_.emplace(rt);
      rt = rt->left;
    }
    return top->val;
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return not stc_.empty();
  }
  
private:
  stack<TreeNode*> stc_;
  
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
