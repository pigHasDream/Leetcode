class Solution {
public:
  int maxSubarraySumCircular(vector<int>& A) {
    int curMax = 0;
    int resMax = INT_MIN;
    int curMin = 0;
    int resMin = INT_MAX;
    
    int sum = 0;

		/* There are only 2 cases, self and concatenate
		 * self is the same as Kadane
		 * concatenate is same as sum - min(Kadane)
		 * Only final special case is all numbers are negative,
		 *  we need to return resMax instead of sum-min(Kadane). */

    for(const auto& n : A) {
      sum += n;
      curMax += n;
      curMin += n;
      
      resMax = max(resMax, curMax);
      resMin = min(resMin, curMin);
      
      curMax = curMax < 0 ? 0 : curMax;
      curMin = curMin > 0 ? 0 : curMin;
    }
    
    return resMax > 0 ? max(sum-resMin, resMax) : resMax;
  }
};


