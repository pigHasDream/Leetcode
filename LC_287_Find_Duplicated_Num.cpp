class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    
    // This problem views each number as index
    // If we have multiple same number, we'll see a 
    // loop. But we only use O(1) space, so detecting a 
    // loop can use 2 pointers, slow and fast, fast == 2slow.
    
    int size = nums.size();
    if(size == 0) return -1;
   
    int slow = nums[0];
    int fast = nums[0];
    
    // Find the meet point, not necessarily the same point 
    // of duplications
    do{
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while(slow != fast);
    
    slow = nums[0];
    
    // Then, find the loop start point
    while(slow!=fast) {
      slow= nums[slow];
      fast= nums[fast];
    }
    
    return slow;
  }
};
