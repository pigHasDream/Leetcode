class Solution {
public:
  bool stoneGame(vector<int>& piles) {
    
    // check for MIT 6.046J lecture 10 last example.
    
    int n = piles.size();
    // memo records the i~j range, Alex max value can get 
    // assuming bob is also playing optimal
    
    vector<vector<int>> memo(n, vector<int>(n, -1));
    
    function<int(int,int)> doDFS = [&](int left, int right) {
      if(memo[left][right] != -1) return memo[left][right];
      if(left == right) return memo[left][right] = piles[left];
      if(left + 1 == right) return memo[left][right] = max(piles[left], piles[right]);
      
      // outter max is the max of current move
      // inner min is the guaranteed next next move after opponent's choice,
      // where opponent will pick the best value for him,
      // so we will get a minimum for sure!
      return memo[left][right] = max(doDFS(left,left) + min(doDFS(left+2, right), doDFS(left+1, right-1)),
                                     doDFS(right,right) + min(doDFS(left, right-2), doDFS(left+1, right-1)));
    };

    return 2*doDFS(0, n-1) > accumulate(piles.begin(), piles.end(), 0);
  }
};
