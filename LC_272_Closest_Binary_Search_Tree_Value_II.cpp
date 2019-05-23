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
  vector<int> closestKValues(TreeNode* root, double target, int k) {

    stack<TreeNode*> stc;
    deque<int> que;
    
    TreeNode* rt = root;
    
    while(rt or stc.size()) {
      while(rt) {
        stc.push(rt);
        rt = rt->left;
      }
      
      auto top = stc.top();
      stc.pop();
      
      // keep a sliding window of size k
      // while traversing in order
      // if size becomes bigger than k, 
      // need to conditionally remove the front of deque.
      if(que.size() < k) {
        que.emplace_back(top->val);
      }
      else {
        if(top->val - target < target - que.front()) {
          que.pop_front();
          que.emplace_back(top->val);
        }
        else {
          // This is optional, but can early terminate the loop
          break;
        }
      }
      
      rt = top->right;
    }
    
    return vector<int>(que.begin(), que.end());
  }
};`
