// This solution takes O(n) time and O(1) space

class Solution {
public:
  bool isPalindrome(ListNode* head) {
    if(head == nullptr) return true;
    
    // step 1: find the middle point
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast != nullptr and fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    
    ListNode* leftEnd = slow;
    // step 2: reverse the 2nd half 
    ListNode* nPtr = nullptr;
    ListNode* cPtr = leftEnd->next;
    ListNode* pPtr = leftEnd;
    while(cPtr) {
      nPtr = cPtr->next;
      cPtr->next = pPtr;
      pPtr = cPtr;
      cPtr = nPtr;
    }
    
    // step 3: compare 1st and 2nd half
    ListNode* end = pPtr;
    ListNode* start = head; 
    bool isPalindrome(true);
    while(end != leftEnd) {
      if(start->val != end->val) {
        isPalindrome = false;
        break;
      }
      start = start->next;
      end = end->next;
    }
    
    // step 4: reverse back the 2nd half
    nPtr = nullptr;
    cPtr = pPtr;
    pPtr = nullptr;
    while(cPtr != leftEnd) {
      nPtr = cPtr->next;
      cPtr->next = pPtr;
      pPtr = cPtr;
      cPtr = nPtr;
    }
    
    leftEnd->next = pPtr;
    
    return isPalindrome;
  }
};
