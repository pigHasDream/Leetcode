class Solution {
public:
  ListNode* deleteNodes(ListNode* head, int m, int n) {
    ListNode phead(0, head);
    int idx = 1;
    
    while(head) {
      while(head and idx < m) {
        head = head->next;
        ++idx;
      }
      
      idx = 0;
      while(head and head->next and idx < n) {
        auto tmp = head->next;
        // This is the best approach to skip an elem in a list!
        head->next = head->next->next;
        delete tmp;
        ++idx;
      }
      idx = 0;
    }
    
    return phead.next;
  }
};
