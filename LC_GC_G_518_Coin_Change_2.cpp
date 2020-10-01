// ----------------------------------------------
class Solution {
public:
  int change(int amount, vector<int>& coins) {
    
    vector<vector<int>> memo(amount+1, vector<int>(coins.size(), -1));
    
    // here the signature is current sum and the index of coins
    // Memo also need to be 2-D, here idx means use coins up to idx
    function<int(int,int)> doDFS = 
      [&] (int curSum, int idx) {
      if(curSum == 0) return 1;
      if(curSum < 0) return 0;
      if(idx == coins.size()) return 0;
      
      int& ans = memo[curSum][idx];
      if(ans != -1) return ans;
      
      ans = 0;
      ans += doDFS(curSum-coins[idx], idx);
      ans += doDFS(curSum, idx+1);
      
      return ans;
    };

    return doDFS(amount, 0);
  }
};


// ----------------------------------------------
class Solution {
public:
  int change(int amount, vector<int>& coins) {
    
    vector<int> dp(amount+1,0);
    dp.front() = 1;
    
    for(int i=0; i<coins.size(); ++i) {
      for(int j=1; j<=amount; ++j) {
        if(j>=coins[i]) {
          dp[j] += dp[j-coins[i]];
        }
      }
    }
    
    return dp.back();
  }
};


// ----------------------------------------------
class Solution {
public:
  int change(int amount, vector<int>& coins) {
    
    vector<int> dp(amount+1,0);
    dp.front() = 1;
    
    // Note that this coin change2 below outer loop checks for the coins
    // This way avoids the duplications! Because, every time a new coin
    // comes in, there is no duplications
    // For LC377 Combination Sum IV, the 2-level loop swaps, and that gives 
    // exhaustive permutations (with duplications).
    for(int i=0; i<coins.size(); ++i) {
      // Here it means by using the new value, what is the total count!
      for(int j=coins[i]; j<=amount; ++j) {
        dp[j] += dp[j-coins[i]];
      }
    }
    
    return dp.back();
  }
};
