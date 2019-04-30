class Solution {
public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    
    ListNode pivot(0);
    ListNode* prev(&pivot);
    ListNode* cur(nullptr);
    
    prev->next = head;
    
    for(int i=0; i<m-1; ++i)
      prev = prev->next;
    
    cur = prev->next;
    for(int i=0; i<n-m; ++i) {
      auto tmp = prev->next;
      prev->next = cur->next;
      cur->next = cur->next->next;
      prev->next->next = tmp;
    }
    
    return pivot.next;

  }
};
