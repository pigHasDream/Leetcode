class Solution {
public:
  TreeNode* sortedListToBST(ListNode* head) {
    theHead_ = head;
    
    int size = 0;
    ListNode* curHead(head);
    while(curHead) {
      ++size;
      curHead = curHead->next;
    }
      
   return constructBST(1, size+1);
  }
  
  // Simulate the in order traversal
  // each time we return from left child build,
  // theHead_ pointer moves towards one point.
  TreeNode* constructBST(int left, int right) {
    
    if(left >= right)
      return nullptr;
    
    int mid = left + (right - left)/2;
    
    TreeNode* leftNode =  constructBST(left, mid);
    TreeNode* newRoot = new TreeNode(theHead_->val);
    newRoot->left = leftNode;
    theHead_ = theHead_->next;
    newRoot->right = constructBST(mid+1, right);
    
    return newRoot;
  }
  
private:
  ListNode* theHead_;
  
};
