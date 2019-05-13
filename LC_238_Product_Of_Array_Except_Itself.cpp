// The first solution uses 2 arrays to store from left
// and from right side of products.
// Finally go through the case.
class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> leftProd(nums.size(), 1);
    vector<int> rightProd(nums.size(), 1);
   
    for(int i=0; i<nums.size(); ++i) {
      leftProd[i] = i==0 ? 1 : leftProd[i-1]*nums[i-1];
    }
      
    for(int i=nums.size()-1; i>=0; --i) {
      rightProd[i] = i==nums.size()-1 ? 1 : rightProd[i+1]*nums[i+1];
    }
    
    vector<int> res(nums.size(), 1);
    for(int i=0; i<nums.size(); ++i) {
      res[i] = leftProd[i]*rightProd[i];
    }

    return res;
  }
};


// Below optimized version can merge above 3 loops to 1.
// But here I put it separately as 2 loops.
// We use constant rolling paramenter to keep track of
// the product changes in left and right.

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
     
    int leftProd = 1;
    int rightProd = 1;
    vector<int> res(nums.size(), 1);
    
    for(int i=0; i<nums.size(); ++i) {
      res[i] *= leftProd;
      leftProd *= nums[i];
    }
    
    for(int i=nums.size()-1; i>=0; --i) {
      res[i] *= rightProd;
      rightProd *= nums[i];
    }

    return res;
  }
};


// Merge the 2 pass into single pass
class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
     
    int leftProd = 1;
    int rightProd = 1;
    vector<int> res(nums.size(), 1);
    
    for(int i=0; i<nums.size(); ++i) {
      res[i] *= leftProd;
      leftProd *= nums[i];
      res[nums.size()-1-i] *= rightProd;
      rightProd *= nums[nums.size()-1-i];
    }

    return res;
  }
};
