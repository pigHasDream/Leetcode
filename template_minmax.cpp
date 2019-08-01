class Solution {
public:
  int game(vector<int>& vec) {

    // get some memo due to repeating
    vector<vector<int>> memo(n, vector<int>(n, -1));
    
    // The main recursion essense is 
    // return "the optimal score if current guy starts 
    // with current state config"

    function<int(State)> doDFS = [&](State currState) {
      if(...) // base case
      if(memo[currState] != -1) return memo[currState];
      
      int res = 0;
      // possible scanning through possible cases
      // KEY IS:
      // doDFS defines whoever starts from this given state,
      // what would be the "global optimal" return score
      // of that guy! no matter who!

      // So, the current person would simply use the total
      // remaining score subtract the other guy's return
      for(nextState : allPossibleNextStates) {
        res = max(res, TotalRemainScore - doDFS(nextState));
      }
      
      return memo[currState] = res;
    };

    // the first guy's score
    return doDFS(initialState);

    // the second guy's score
    // return doDFS(state after initialState);
  }
};
