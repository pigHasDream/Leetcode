class Solution {
public:
  int minCostII(vector<vector<int>>& costs) {
    int nH = costs.size();
    if(nH == 0) return 0;
    int nC = costs.front().size();
    if(nC == 0) return 0;
    
    int min1 = 0, min2 = 0, minColor = -1;
    
    for(int i=0; i<nH; ++i) {
      int curMin1 = INT_MAX, curMin2 = INT_MAX, curMinColor = -1;
      
      for(int j=0; j<nC; ++j) {
        int cost = costs[i][j] + (minColor == j ? min2 : min1);
        
        if(cost <= curMin1) {
          curMin2 = curMin1;
          curMin1 = cost;
          curMinColor = j;
        }
        else if(cost < curMin2) {
          curMin2 = cost;
        }
      }
      
      min1 = curMin1;
      min2 = curMin2;
      minColor = curMinColor;
    }

    return min1;
  }
};




class Solution {
public:
  int minCostII(vector<vector<int>>& costs) {
    int nH = costs.size();
    if(nH == 0) return 0;
    int nC = costs.front().size();
    
    vector<vector<int>> dp(nH, vector<int>(nC, INT_MAX));
    
    for(int i=0; i<nH; ++i) {
      for(int j=0; j<nC; ++j) {
        // This internal for-loop can be replaced
        // as we don't really need to loop through the vector
        // to get the min value.
        // That's why we only keep 2 min values
        if(i==0) {
          dp[0][j] = costs[0][j];
        }
        else {
          for(int k=0; k<nC; ++k) {
            if(k==j) continue;
            // here the dp[i-1][k] looping over nC is not necessary
            // we can just keep the min value of previous iteration.
            // But we need to deal with the conflict case!
            // That's why we need a 2nd min case
            dp[i][j] = min(dp[i][j], dp[i-1][k]+costs[i][j]);
          }
        }
      }
    }

    return *min_element(dp.back().begin(), dp.back().end());
  }
};
