class Solution {
public:
  int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
    const int inf = 1e8;
    vector<vector<vector<int>>> memo(m+1, vector<vector<int>>(n+1, vector<int>(target+1, -1)));
    
    // minCost (index, prevColor, remain target needed)
    function<int(int,int,int)> doDFS = 
      [&](int idx, int prevColor, int tar) -> int {
      
      if(idx == m or tar < 0) {
        if(tar == 0) return 0;
        return inf;
      }
      
      int &ret = memo[idx][prevColor][tar];
      if(ret != -1) return ret;
      ret = inf;
      
      if(houses[idx]!=0) {
        ret = doDFS(idx+1, houses[idx], prevColor == houses[idx] ? tar : tar-1);
        return ret;
      }
      
      for(int color=1; color<=n; ++color) {
        ret = min(ret, cost[idx][color-1] + doDFS(idx+1, color, color == prevColor ? tar : tar-1));
      }
      
      return ret;
    };

    int res = doDFS(0, 0, target);
    
    return res < inf ? res : -1;
  }
};
