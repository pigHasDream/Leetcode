class Solution {
public:
  string shortestSuperstring(vector<string>& A) {
    const int sz = A.size();
    const int inf = INT_MAX/2;
    vector<vector<int>> graph(sz, vector(sz, 0));
    
    // convert the problem to TSP
    for(int i=0; i<sz; ++i) {
      for(int j=0; j<sz; ++j) {
        graph[i][j] = A[j].size();
        for(int k=1; k<=min(A[i].size(), A[j].size()); ++k) {
          if(A[i].substr(A[i].size()-k) == A[j].substr(0,k)) {
            // the cost is how many bits the suffix needs
            graph[i][j] = A[j].size()-k;
          }
        }
      }
    }
    // memo state records from a given set of nodes visited
    // and the last node being visited 
    vector<vector<pair<int,string>>> memo(1<<sz, vector<pair<int,string>>(sz, {-1, ""}));
    
    // The return of the doDFS is: what is the addtional len needed to cover all strings;
    // the pair<additional len, addtional string>
    function<pair<int,string>(int,int)> doDFS =
      [&](int prev, int state) -> pair<int,string> {
      
      if(state == (1<<sz)-1) {
        return {0, ""};
      }
      
      auto& ans = memo[state][prev];
      if(ans.first != -1) return ans;
      
      ans = {inf, ""};
      
      for(int k=0; k<sz; ++k) {
        if(state & (1<<k)) continue;
        string leftStr = state == 0 ?  A[k] : A[k].substr(A[k].size()-graph[prev][k]);
        auto [len, rightStr] = doDFS(k, state | (1<<k));
        
        if(leftStr.size()+len < ans.first) {
          ans = {leftStr.size()+len, leftStr + rightStr};
        }
      }
      
      return ans;
    };
    
    return doDFS(0, 0).second;
  }
};
