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
  ListNode* removeZeroSumSublists(ListNode* head) {
    // stc <ListNode, prefixSum>
    stack<pair<ListNode*,int>> stc;
    // hash: <prefix sum, first idx shows up the prefixSum>
    unordered_map<int, int> hash;
    // the initial position is needed
    hash[0] = -1;
    
    ListNode dummyHead(INT_MAX);
    dummyHead.next = head;
    ListNode* node = head;
    stc.emplace(&dummyHead,0);
    
    for(int idx=0; node!=nullptr; ++idx) {
      auto next = node->next;
      
      stc.emplace(node, stc.top().second + node->val);
      auto top = stc.top();
      int sum = top.second;
 
      if(hash.count(sum)) {
        for(int k=idx-hash[sum]; k>0; --k) {
          // very important key: only erase the hash that are not equal to the 
          // current target sum key! the current sum key is needed for future iteration!
          if(stc.top().second != sum) hash.erase(stc.top().second);
          stc.pop();
          // here we need to also decrease the idx to adjust the hash for new elements
          --idx;
        }
        
        stc.top().first->next = next;
      }
      else {
        hash[sum] = idx;
      }  
      
      node = next;
    }
    
    return dummyHead.next;
  }
};
