class Solution {
public:
  int missingElement(vector<int>& nums, int k) {
    
    //nums[i]   4 7 9 10     k=3
    //idx       0 1 2 3
    //miss      0 2 3 3      nums[i]-nums.front()-idx
    
    for(int i=0; i<nums.size(); ++i) {
      if(nums[i]-nums.front()-i >= k) {
        // return nums[i-1] + k - (nums[i-1] - nums.front() - (i-1));
        return k + nums.front() + (i-1);
      }
    }

    return k + nums.front() + nums.size()-1;
  }
};


class Solution {
public:
  int missingElement(vector<int>& nums, int k) {
    
    //nums[i]   4 7 9 10     k=3
    //idx       0 1 2 3
    //miss      0 2 3 3      nums[i]-nums.front()-idx
    
    // search for the left s.t. there are just enough missing element 
    // between [... left] idx
    int left = 0, right = nums.size();
    while(left < right) {
      int mid = left + (right-left)/2;
      
      if(nums[mid]-nums.front()-mid >= k) {
        right = mid;
      }
      else {
        left = mid+1;
      }
    }

    // return nums[left-1] + k - (nums[left-1] - nums.front() - (left-1));
    return k + nums.front() + (left-1);
  }
};
