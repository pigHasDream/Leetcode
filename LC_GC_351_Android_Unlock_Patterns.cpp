class Solution {
public:
  int numberOfPatterns(int m, int n) {
    map<pair<int, int>, int> checkMap { 
      {{1, 3}, 2},
      {{1, 7}, 4},
      {{1, 9}, 5},
      {{2, 8}, 5},
      {{3, 1}, 2},
      {{3, 7}, 5},
      {{3, 9}, 6},
      {{4, 6}, 5},
      {{6, 4}, 5},
      {{7, 1}, 4},
      {{7, 9}, 8},
      {{7, 3}, 5},
      {{8, 2}, 5},
      {{9, 1}, 5},
      {{9, 7}, 8},
      {{9, 3}, 6}
                                      };
    // permutation problem that counts the number can always be converted to
    // a combination problem, just like TSP using DP to reduce the runtime.
    // Here we use DP to record the state!! so we can convert it to combination
    // We don't really care about the internal sequence of that combination!
       
    vector<vector<int>> memo(10, vector<int>(1<<10, -1));
    
    function<int(int, int, int)> doDFS = 
      [&](int pos, int count, int state) -> int {
      
      if(count > n) return 0;
      
      int& ret = memo[pos][state];
      
      if(ret != -1) {
        return ret;
      }
      
      if(count >= m and count <= n) 
        ret = 1; 
      else 
        ret = 0;
      
      for(int i=1; i<=9; ++i) {
        if(state & (1<<i)) continue;
        
        if(checkMap.count({pos,i}) == 0 or ((1<< checkMap[{pos,i}]) & state)) {
          int delta = doDFS(i, count+1, state | (1<<i));
          ret += delta;
        }
      }
      
      return ret;
    };
    
    return doDFS(0, 0, 0);
  }
};
