class Solution {
public:
  bool canCross(vector<int>& stones) {
    int n = stones.size();
    // dp[i] refers to the i-th stone, what is the
    // corresponding available jump.
    // empty means not ok.
    
    // This is essentially still a BFS based approach!
    unordered_map<int, unordered_set<int>> dp;
    for(const auto& s : stones) dp[s] = {};
    
    dp[0].insert(1);
    
    // This loop checks every stone, and based on
    // the available next steps stored on this stone,
    // we can decide the next stone's steps!
    
    // This is essentially a BFS based idea!
    // If we do pure DP Base approach, it'll take
    // N^3 complexity!
    for(int i=0; i<n; ++i) {
      for(const auto& step : dp[stones[i]]) {
        int nextStone = stones[i] + step;
        if(nextStone == stones.back()) return true;
        if(dp.count(nextStone)) {
          if(step>0) dp[nextStone].insert(step);
          if(step-1>0) dp[nextStone].insert(step-1);
          dp[nextStone].insert(step+1);
        }
      }
    }

    return false;
  }
};
