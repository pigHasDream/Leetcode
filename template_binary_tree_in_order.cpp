// ---------------------------------------------
vector<int> inorderTraversal(TreeNode* root) {
  vector<int> res;
  auto rt = root;
  stack<TreeNode*> st;

  while(rt or st.size()) {
    while(rt) {
      st.push(rt);
      rt = rt->left;
    }

    auto top = st.top(); st.pop();
    rt = top->right;
    // do something to the popped top elem
    res.emplace_back(top->val);
  }

  return res;
}

// ----------------------------------------------
// The exact iterative procedure is split to make
// a BST iterator class!
// ----------------------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) 
       : val(x), left(NULL), right(NULL) {}
 * };
 */

class BSTIterator {

public:
  BSTIterator(TreeNode* root) {
    pushNext(root);
  }

  /** @return the next smallest number */
  int next() {
    auto top = stack_.top();
    stack_.pop();
    pushNext(rt->right);
    return top->val;
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return stack_.size();
  }
  
private:
  stack<TreeNode*> stack_;
  
  void pushNext(TreeNode* root) {
    while(root) {
      stack_.push(root);
      root =  root->left;
    }
  }
  
};

/**
 * Your BSTIterator object 
 * will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
