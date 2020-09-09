class Solution {
public:
  int minSumOfLengths(vector<int>& arr, int target) {
    constexpr int inf = 1e9;
    int sz = arr.size();
    int sum = 0;
    int left=0;
    // min length of ending at i-th position meet with target sum
    vector<int> dp(sz, inf);
    int minLen = inf;
    int res = inf;
    
    for(int right=0; right<sz; ++right) {
      sum += arr[right];
      
      while(sum > target) sum -= arr[left++];
        
      if(sum == target){
        int len = right-left+1;
        
        // here is the key! dp[left-1] naturally separate the current
        // array and previous array.
        if(left > 0 and dp[left-1] != inf) {
          res = min(res, len + dp[left-1]);
        }
        
        // keep track of global minLen to continue updating the dp array!
        // it records "so far" the shortest subarray I can see!
        minLen = min(minLen, len);
      }
      // it records "so far" the shortest subarray I can see!
      dp[right] = minLen;
    }
    
    return res == inf ? -1 : res;
  }
};
