class Solution {
public:
  int minDays(int n) {
    // Top down case using map will save a lot of consecutive saving case and make it fast!!
    unordered_map<int,int> memo;
    
    function<int(int)> doDFS = [&] (int m) {
      if (m <= 1)
        return 1;
      
      if(memo.count(m)==0)
        // m%3 + doDFS(m/3) means if m%3 != 0, it will take m%3 days to get m%3==0. Then we can do m/3
        // same for m%2 case.
        // This is implictly adding up the -1 case which takes most of the runtime!!!
        // This has to be done by top down because it kills unnecesary caching!
        memo[m] = 1 + min(m%3+doDFS(m/3), m%2+doDFS(m/2));
      
      return memo[m];
    };
    
    int ret = doDFS(n);
    for(const auto & p : memo)
      cout << p.first << " " << p.second << endl;
    
    return ret;
  }

};
