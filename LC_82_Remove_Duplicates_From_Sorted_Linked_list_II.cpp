class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode pivot(0);
    pivot.next = head;
    
    ListNode* prev(&pivot);
    ListNode* curr(head);
    while(curr) {
      int tVal = curr->val;
      bool toDeleteCur(false);
      
      // delete any node dup with cur
      while(curr->next and curr->next->val == tVal) {
        toDeleteCur = true;
        auto next = curr->next->next;
        delete curr->next;
        curr->next = next;
      }
      // delete cur node as well
      if(toDeleteCur) {
        prev->next = curr->next;
        delete curr;
        curr = prev->next;
      }
      // normal case, move forward
      else {
        prev = curr; 
        curr = curr->next;
      }
    }

    return pivot.next;
  }
};
