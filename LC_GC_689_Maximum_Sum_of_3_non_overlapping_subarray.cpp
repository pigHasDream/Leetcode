class Solution {
public:
  vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {

    // first convert the fixed window sum to a single number by O(N) scan
    vector<int> sums(nums.size()-k+1,0);
    int slow = 0; int fast = 0;
    while(fast < nums.size()) {
      if(fast - slow + 1 <= k) {
        sums[slow] += nums[fast];
      }
      else {
        sums[++slow] = sums[slow] + nums[fast] - nums[slow];
      }
      ++fast;
    }
    
    // use DP to book keep from left to current node what is the
    // max value and the position index pair
    vector<pair<int,int>> leftMax(sums.size(), {0,-1});
    pair<int,int> leftMaxPair = {0, -1};
    for(int i=0; i<sums.size(); ++i) {
      if(sums[i] > leftMaxPair.first)
        leftMaxPair = {sums[i], i};
      
      leftMax[i] = leftMaxPair;
    }
    
    // use DP to book keep from right to current node what is the
    // max value and the position index pair
    vector<pair<int,int>> rightMax(sums.size(), {0,-1});
    pair<int,int> rightMaxPair = {0, -1};
    for(int i=sums.size()-1; i>=0; --i) {
      if(sums[i] >= rightMaxPair.first)
        rightMaxPair = {sums[i], i};
      
      rightMax[i] = rightMaxPair;
    }

    // Finally take a O(N) scan for middle number and paired with the
    // left and right max value to find the best results!
    vector<int> res;
    int cur = 0;
    int sz = sums.size();
    for(int i=k; i<sz-k; ++i) {
      int newSum = leftMax[i-k].first + sums[i] + rightMax[i+k].first;
      if(cur < newSum) {
        cur = newSum;
        res = vector<int>({leftMax[i-k].second, i, rightMax[i+k].second});
      }
    }
    
    return res;
  }
};
