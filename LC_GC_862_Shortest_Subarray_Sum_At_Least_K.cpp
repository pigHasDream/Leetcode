class Solution {
public:
  int shortestSubarray(vector<int>& A, int K) {
    int sz = A.size();
    int sum = 0;
    // Because the array contains negative numbers,
    // classical sliding window won't work out as it's not monotonic.
    // Now, to tackle with the "left" pointer issue, we can artificially
    // create a "monotonic" array, which only records increasing "discrete"
    // indexes. So that the sliding window feature still holds inside the queue.
    // 
    //
    // pair<prefixSum, index>
    // deque is monotonically increasing
    deque<pair<int,int>> que;
    constexpr int inf = 1e9;
    int res = inf;
    
    for(int i=0; i<sz; ++i) {
      sum += A[i];
      if(sum >= K)
        res = min(res, i+1);
      
      // deque is monotonically increasing,
      // so we can keep moving the "left" pointer
      // out of the deque to get the prefixsum subtraction
      // until the left pointer element is too big to continue
      while(que.size() and sum - que.front().first >= K) {
        res = min(res, i - que.front().second);
        que.pop_front();
      }
      // maintain a monotonically increasing deque
      // We are doing a subtraction, so bigger element is
      // not helping! We need to keep the nearest smaller elem
      while(que.size() and que.back().first > sum) {
        que.pop_back();
      }
      
      que.emplace_back(sum, i);
    }
    
    return res == inf ? -1 : res;
  }
};
