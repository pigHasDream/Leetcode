class Solution {
public:
  int findPaths(int m, int n, int N, int i, int j) {
    const int mod = 1e9+7;
    
    int memo[52][52][52];
    memset(memo, -1, sizeof memo);
    
    vector<int> dir{0,1,0,-1,0};
    
    function<int(int,int,int)> doDFS = 
      [&](int x, int y, int k) {
      if(x<0 or x>=m or y<0 or y>=n)
        return 1;
      
      if(k==0) return 0;
      
      int& ans = memo[x][y][k];
      if(ans != -1)
        return ans;
      
      ans = 0;
      for(int d=0; d<4; ++d) {
        int xx = x+dir[d];
        int yy = y+dir[d+1];
        
        ans = (ans + doDFS(xx, yy, k-1)%mod)%mod;
      }
      
      return ans;
    };

    return doDFS(i, j, N);
    
  }
};
