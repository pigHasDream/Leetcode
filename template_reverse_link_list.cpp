/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// ---------------------------------
// reverse linked list iterative
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


// ---------------------------------
// reverse linked list recursion

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


// ---------------------------------
// reverse linked list between m to n

class Solution {
public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    if(head == nullptr) return nullptr;
    ListNode dummy(0);
    dummy.next = head;
    ListNode* ptr(&dummy);
    ListNode* pptr(&dummy);
    
    int count = 0;
    while(count < m) {
      pptr = ptr;
      ptr = ptr->next; 
      ++count;
    }
    
    ListNode* leftEnd(pptr);
    ListNode* rightStart(ptr);
    ListNode* cptr(ptr);
    ListNode* nptr(nullptr);
    
    while(count<=n) {
      nptr = cptr->next;
      cptr->next = pptr; 
      pptr = cptr;
      cptr = nptr;
      ++count;
    }
    
    leftEnd->next = pptr;
    rightStart->next = cptr;
    
    return dummy.next;
  }
};
