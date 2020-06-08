class Solution {
public:
  int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
    
    const int inf = 1e6+1;
    
    vector<vector<vector<int>>> memo(m+1, vector<vector<int>>(n+1, vector<int>(target+1, -1)));
    
    function<int(int,int,int)> doDFS = [&] (int idx, int prevColor, int nTar) {
      
      int res = inf;
      
      if(nTar < 0) return res;
      
      if(idx == m) {
        if(nTar == 0) {
          res = memo[idx][prevColor][nTar] = 0;
        }
        return res;
      }
      
      if(memo[idx][prevColor][nTar] != -1) 
        return memo[idx][prevColor][nTar];
      
      if(houses[idx] != 0) {
        return memo[idx][prevColor][nTar] = doDFS(idx+1, houses[idx], prevColor == houses[idx] ? nTar : nTar - 1);
      }

      for(int c=1; c<=n; ++c) {
        res = min(res, cost[idx][c-1] + doDFS(idx+1, c, c == prevColor ? nTar : nTar - 1));
      }
      
      return memo[idx][prevColor][nTar] = res;
    };

    int ans = INT_MAX;
    ans = doDFS(0, 0, target);
    
    return ans >= inf ? -1 : ans;
  }
};
