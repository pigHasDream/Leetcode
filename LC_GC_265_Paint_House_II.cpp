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
