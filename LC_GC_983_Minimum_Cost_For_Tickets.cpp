class Solution {
public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    
    vector<int> dp(days.back()+1, 0);
    unordered_set<int> hash(days.begin(), days.end());
    
    for(int i=1; i<=days.back(); ++i) {
      if(hash.count(i) == 0) {
        dp[i] = dp[i-1];
        continue; 
      }
      
      dp[i] = min(min(dp[max(0,i-1)]+costs[0], dp[max(0, i-7)]+costs[1]),
                  dp[max(0,i-30)]+costs[2]);
      
    }
    
    return dp.back();
  }
};



class Solution {
public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    unordered_set<int> hash(days.begin(), days.end());
    
    vector<int> memo(days.back()+1, -1);
    function<int(int)> doDFS = [&] (int idx) {
      if(idx <= 0) 
        return 0;
      
      if(memo[idx] != -1)
        return memo[idx];
      
      if(hash.count(idx) == 0)
        return memo[idx] = doDFS(idx-1);
      
      return  memo[idx] = min(doDFS(idx-1) + costs[0],
                              min(doDFS(idx-7) + costs[1], 
                                  doDFS(idx-30) + costs[2]));
    };
    
    return doDFS(days.back());
  }
};
