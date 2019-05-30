class Solution {
public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return doBinary(nums, 0, nums.size());
  }
  
  TreeNode* doBinary(const vector<int>& nums, int left, int right) {
    if(left>=right) return nullptr;
    
    int mid = left + (right-left)/2;
    
    auto root = new TreeNode(nums[mid]);
    root->left = doBinary(nums, left, mid);
    root->right = doBinary(nums, mid+1, right);
    
    return root;
  }
};
