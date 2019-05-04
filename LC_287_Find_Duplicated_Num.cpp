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

  int findDuplicate(vector<int>& nums) {
    
    // binary search based count.
    // based on the fact that 1~i, we should have counts <= i.
    // if more than that, we can say there must be duplications!
    
    int left = 0, right = nums.size();
    while(left < right) {
      int mid = left + (right - left)/2;
      
      // Note that we always traverse the entire array range.
      // Only the mid threshold is performing a binary search!
      int count = count_if( nums.begin(), nums.end(), 
													  [mid](const auto& val){ return val <= mid;});
      if(count > mid) {
        right = mid;
      }
      else {
        left = mid+1;
      }
    }
    
    return left;
  }

  
};
