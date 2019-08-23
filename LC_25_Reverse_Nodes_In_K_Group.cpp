/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode dummyHead(0);
    dummyHead.next = head;
    ListNode* node(&dummyHead);
    
    int size = 0;
    while(node->next) {
      ++size;
      node = node->next;
    }
    
    node = &dummyHead;
    int total = 0;
    while(node->next and size - total >= k) {
      
      int count = 1;
      ++total;
      ListNode* PrevNode = node;
      ListNode* StartNode = node->next;
      
      ListNode* curr = node->next;
      ListNode* next = curr->next;
      while(next and count < k) {
        auto tmp = next->next;
        next->next = curr;
        curr = next;
        next = tmp;
        ++count;
        ++total;
      }
      
      PrevNode->next = curr;
      StartNode->next = next;
      node = StartNode;
      
    }
    
    return dummyHead.next;
  }
};
