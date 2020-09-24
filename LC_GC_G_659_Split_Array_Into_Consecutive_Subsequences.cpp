// Similar to LC 1296, LC 846, but here we can have either 3 or more 
// length of consecutive numbers!
//
// Now, we can do greedy. The key is:
// as long as freqMap[n+1] >= freqMap[n], we can continue
// the previous sequence, because, n+1 may have extra elem.
// Otherwise, we need to stop here and start a new sequence!
//
// https://leetcode.com/problems/split-array-into-consecutive-subsequences/discuss/630988/Very-short-C%2B%2B-O(n)-time-simple-greedy

class Solution {
public:
  bool isPossible(vector<int>& nums) {
    
    unordered_map<int, int> freqMap;
    for (int i: nums) 
      ++freqMap[i];

    int prevCnt = 0;
    
    for (const auto& cur : nums){
      if (freqMap[cur] == 0) 
        continue;
      
      prevCnt = freqMap[cur]--;
      int nxt = cur+1;
      
      // KEY: we compare the previous frequency vs the current frequency
      // as long as the new one is higher or equal, we can greedily extend the
      // old sequence.
      while(freqMap[nxt] >= prevCnt){
        prevCnt = freqMap[nxt]--; 
        ++nxt;
      }
      
      if (nxt - cur < 3) 
        return false;
    }
    
    return true;
  }
};
