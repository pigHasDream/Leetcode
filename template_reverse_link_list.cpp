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
  ListNode* reverseList(ListNode* head) {

    ListNode* nPtr = nullptr;
    ListNode* pPtr = nullptr;
    ListNode* cPtr = head;
    
    while(cPtr != nullptr) {
      nPtr = cPtr->next;
      cPtr->next = pPtr;
      pPtr = cPtr;
      cPtr = nPtr;
    }

   return pPtr;
  }
};


class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if(head == nullptr or head->next == nullptr) 
      return head;
    
    auto root = reverseList(head->next);
    
    // head->next is the tail of root's chain
    // head->next->next is the next pointer to be
    // connected to head
    head->next->next = head;
    
    // clean up the old head->next pointer
    head->next = nullptr;
    
    return root;
  }
};
