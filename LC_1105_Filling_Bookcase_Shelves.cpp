class Solution {
  
public:
  int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
    int size = books.size();
    const int mx = 1001*1001;
    vector<int> dp(size, mx);
    
    for(int i=0; i<size; ++i) {
      int h = 0;
      int w = 0;
      
      for(int j=i; j>=0; --j) {
        w += books[j][0];
        if(w > shelf_width) break;
        h = max(h, books[j][1]);
        dp[i] = min(dp[i], (j == 0 ? 0 : dp[j-1]) + h);
      }
    }
    
    return dp.back();
  }
  
};
