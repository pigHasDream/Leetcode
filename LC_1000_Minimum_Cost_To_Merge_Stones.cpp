class Solution {
public:
  int mergeStones(vector<int>& stones, int K) {
    const int n = stones.size();
    if ((n - 1) % (K - 1)) return -1;
    const int kInf = 1e9;    
    
    vector<int> sums(n + 1);
    for (int i = 0; i < stones.size(); ++i) 
      sums[i + 1] = sums[i] + stones[i];
    
    vector<vector<int>> memo(n, vector<int>(n, -1));
    
    std::function<int(int,int)> doDFS = 
      [&](int start, int end) {

      int len = end-start+1;
      if(len<K) return 0;

      if(memo[start][end] != -1) 
        return memo[start][end];

      if(start == end) 
        return memo[start][end] = 0;
      
      int ret = kInf;
      for(int m=start; m<end; m += K-1)
        ret = min(ret, doDFS(start, m) + doDFS(m+1, end));
      
      // Below condition indicates an actual merge happens!
      // If below condition not met, there is no merge!
      // Not all iterations will do actual merge!
      if((len-1)%(K-1) == 0) 
        ret += sums[end+1] - sums[start];
      
      return memo[start][end] = ret;
    };
    
    return doDFS(0, n-1);
  }
};
