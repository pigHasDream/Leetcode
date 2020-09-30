class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    
    const int inf = INT_MAX/2;
    sort(coins.rbegin(), coins.rend());
    
    int minCount = inf;
    vector<vector<int>> memo(amount+1, vector<int>(coins.size(), -1));
    
    function<int(int,int,int)> doDFS = 
      [&](int idx, int curSum, int curCount) {
      if(curSum > amount) return inf;
      if(curCount > minCount) return inf;
      if(idx == coins.size()) return inf;
      
      if(curSum == amount) {
        minCount = min(minCount, curCount);
        return curCount;
      }
      
      int& ans = memo[curSum][idx];
      if(ans != -1) return ans;
      
      return ans = min(doDFS(idx, curSum+coins[idx], curCount+1),
                       doDFS(idx+1, curSum, curCount));
    };

    int ret = doDFS(0,0,0);
    return ret >= inf ? -1 : ret;
    
  }
};



    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
       vector<int> res(amount + 1, 0);
    return coinChange2(coins, amount, res);
    }
   int coinChange2(vector<int>& coins, int amount, vector<int>& res){
        if(amount < 0) return -1;
        if(amount == 0) return 0;
        if(res[amount]) return res[amount];
       int temp = INT_MAX;
        for(int i = 0; i < coins.size(); i++){
            int k = coinChange2(coins, amount - coins[i], res);
            if(k == -1) continue;
            temp = min(temp, 1 + k);
        }
       res[amount] = (temp == INT_MAX) ? -1 : temp;
        return res[amount];
    }
