class Solution {
public:
  int mctFromLeafValues(vector<int>& arr) {
    
    int memo[arr.size()+1][arr.size()+1];
    int maxv[arr.size()+1][arr.size()+1];
    memset(memo, -1, sizeof memo);
    memset(maxv, 0, sizeof maxv);
    
    function<int(int,int)> doDFS = [&](int left, int right) {
      if(left == right) // leaf node excluded 
        return 0;
      
      if(memo[left][right] != -1)
        return memo[left][right];
      
      int ret = INT_MAX;
      for(int i=left; i<right; ++i) {
        ret = min(ret, doDFS(left, i) + doDFS(i+1, right) + maxv[left][i] * maxv[i+1][right]);
      }
      
      return memo[left][right] = ret;
    };
    
    // below get the maxv range. Also a dp procedure.
    for(int i=0; i<arr.size(); ++i)
      maxv[i][i] = arr[i];
      
    for(int k=1; k<arr.size(); ++k)
      for(int i=0; i+k<arr.size(); ++i)
        maxv[i][i+k] = max(maxv[i][i+k-1], arr[i+k]);
          
    return doDFS(0, arr.size()-1);
  }
};
