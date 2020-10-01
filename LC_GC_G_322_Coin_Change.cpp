// This problem can use infinite number of the same elem.
// DFS without memo can also work if we do pruning smartly!
// Key here is we "fast track" the repeat case!
class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    
    const int inf = INT_MAX>>1;
    int res = inf;
    
    sort(coins.rbegin(), coins.rend());
    
    function<void(int,int,int)> doDFS =
      [&](int idx, int curSum, int count) {
      if(curSum > amount) return;
      
      if(curSum == amount) {
        res = min(res, count);
        return;
      }
      
      if(idx == coins.size()) return;
      
      // Here we fast track the repeat!
      for(int repeat = (amount-curSum)/coins[idx]; repeat>=0; --repeat) {
        // If ever the count is worse, we don't go further as 
        // It's only going to be worse!
        if(count + repeat > res) break;
        doDFS(idx+1, curSum + coins[idx]*repeat, count+repeat);
      }
    };
     
    doDFS(0, 0, 0);

    return res >= inf ? -1 : res;
  }
};



// This problem is more suitable for just DP solution
class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    const int inf = INT_MAX >> 1;
    // dp[i] refers to the min count of coins
    // to make sum of i amount
    vector<int> dp(amount+1, inf);
    dp[0] = 0;
    
    for(int i=1; i<=amount; ++i) {
      for(const auto& c : coins) {
        if(c > i) continue;
        
        dp[i] = min(dp[i], dp[i-c] + 1);
      }
    }

    return dp.back() >= inf ? -1 : dp.back();
  }
};
