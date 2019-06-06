class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		
		int n{nums.size()};
		// dp status: the max sum to i-th element and if we have to include the i-th element.
		vector<int> dp(n,0);
		dp[0] = nums[0];
		
		// this one just to keep track of max sum
		int maxS(INT_MIN);
		for(int i=0; i<n; ++i) {
			dp[i] = dp[i-1] > 0 ? dp[i-1] + nums[i] : nums[i];
			maxS = max(maxS, dp[i]);
		}
		
		return maxS;
			
	}
};
