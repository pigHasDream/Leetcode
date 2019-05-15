// There are 3 ways to solve the problem.

// 2 pointers using the fact that once 
// nums[left] + nums[right] is bigger than nums[i],
// it is guaranteed if we move left towards right, 
// all numbers will be valid.
// When seeing sorted array, need to think about 
// 2 pointers!!
class Solution {
public:
  int triangleNumber(vector<int>& nums) {
    if(nums.size()<3) return 0;
    sort(nums.begin(), nums.end());

    int res = 0;
    for(int i=nums.size()-1; i>=0; --i) {
      int left = 0, right = i-1;
      while(left < right) {
        if(nums[left]+nums[right] > nums[i]) {
          res += right - left;
          --right;
        }
        else 
          ++left;
      }
    }

    return res;
  }
};


// using binary search to find the first bigger
// than number, and then use arithmetic to calc
// the distance.
class Solution {
public:
  int triangleNumber(vector<int>& nums) {
    if(nums.size()<3) return 0;
    sort(nums.begin(), nums.end());

    int res = 0;
    for(int i=0; i<nums.size()-2; ++i) {
      for(int j=i+1; j<nums.size()-1; ++j) {
        int left=j+1, right=nums.size();
        int mid=0;
        int sum = nums[i]+nums[j];
        while(left < right) {
          int mid = left + (right-left)/2;
          if(nums[mid] >= sum) {
            right = mid;
          }
          else {
            left = mid+1;
          }
        }
        res += left - 1 - j;
      }
    }

    return res;
  }
};


// brute force approach.
class Solution {
public:
  int triangleNumber(vector<int>& nums) {
    if(nums.size()<3) return 0;
    sort(nums.begin(), nums.end());

    int res = 0;
    for(int i=0; i<nums.size()-2; ++i) {
      for(int j=i+1; j<nums.size()-1; ++j) {
        for(int k=j+1; k<nums.size(); ++k) {
          if(nums[i]+nums[j] > nums[k]) ++res;
          else break;
        }
      }
    }

    return res;
  }
};
