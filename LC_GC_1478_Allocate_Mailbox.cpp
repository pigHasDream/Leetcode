class Solution {
public:
  int minDistance(vector<int>& houses, int k) {
    sort(houses.begin(), houses.end());
    
    int dp[101][101];
    memset(dp, -1, sizeof dp);
    
    // cost[i][j] means:
    // what is the sub total cost of all houses
    // within the i-th and j-th house indexes inclusive
    int cost[101][101];
    memset(cost, 0, sizeof cost);
    
    // Below takes advantages of the FACT that
    // the min total distance between i-th and j-th houses
    // only happens when positioning the house in the 
    // median INDEX house!
    for(int i=0; i<houses.size(); ++i) {
      for(int j=i; j<houses.size(); ++j) {
        for(int t=i; t<=j; ++t) {
          // houses[(i+j)/2] gets the index
          // of median house between i-th and j-th house.
          // This is the mail box location!
          cost[i][j] += abs(houses[(i+j)/2] - houses[t]);
        }
      }
    }
    
    function<int(int,int)> doDFS = 
      [&](int idx, int h) -> int {
      if(h == 0 and idx == houses.size())
        return 0;
      
      if(h == 0 or idx >= houses.size()) 
        return INT_MAX/2;
      
      if(dp[idx][h] != -1) 
        return dp[idx][h];
        
      int ret = INT_MAX/2;
      for(int m = idx; m<houses.size(); ++m) {
        ret = min(ret, cost[idx][m] + doDFS(m+1, h-1));
      }
       
      return dp[idx][h] = ret;
    };
    
    return doDFS(0, k);
  }
};


