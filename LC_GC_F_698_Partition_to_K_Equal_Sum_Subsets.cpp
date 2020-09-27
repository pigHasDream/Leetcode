class Solution {
public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    if(nums.size()<k) return false;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum%k) return false;
    int parSum = sum/k;
    int maxElem = *max_element(nums.begin(), nums.end());
    if(maxElem > parSum) return false;
    
    vector<int> visit(nums.size()+1, 0);
    // This is a NP problem: subset selection is NP
    // Just do DFS search, it can be 2^N.
    // Key for this problem is:
    // Within each subgroup, we just search with startIdx and never start from 0
    // Outside each subgroup, i.e., a new group formed, we need to start from 0
    // We keep a global visit vector to track the status.
    // This whole process is a backtracking process!
    
    function<bool(int,int,int)> doDFS = [&](int curSum, int grpCount, int startIdx) {
      if(grpCount == k and curSum == parSum) return true;
      if(curSum > parSum) return false;
      if(curSum == parSum) {
        return doDFS(0, grpCount+1, 0);
      }
      
      for(int i=startIdx; i<nums.size(); ++i) {
        if(visit[i]==0) {
          visit[i] = 1;
          if(doDFS(curSum+nums[i], grpCount, i)) return true;
          visit[i] = 0;
        }
      }
      
      return false;
    };
    
    return doDFS(0, 1, 0);
  }
};
