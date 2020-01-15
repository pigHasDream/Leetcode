class Solution {
public:
  int palindromePartition(string s, int k) {
    
    int size = s.size();
    
    map<string, int> minFlipHash;
    auto minFlip = [&](string str) -> int {
      
      if(minFlipHash.count(str)) return minFlipHash[str];
      
      int left = 0, right = str.size()-1;
      int ret = 0;
      while(left < right) {
        if(str[left]!=str[right]) ++ret;
        ++left, --right;
      }
      return minFlipHash[str] = ret;
    };
    
    vector<vector<vector<int>>> memo(size, vector<vector<int>>(size, vector<int>(k+1, -1)));
    
    function<int(int,int,int)> doDFS = [&](int left, int right, int part) {
      if(left >= right) return 0;
      if(part < 1) return size;
      
      if(memo[left][right][part] != -1) return memo[left][right][part];
      
      if(part == 1) return memo[left][right][1] = minFlip(s.substr(left, right-left+1));
      
      int ret = size;
      for(int m=left; m<=right; ++m) {
        ret = min(ret, doDFS(left, m, 1) + doDFS(m+1, right, part-1));
      }
      
      return memo[left][right][part] = ret;
    };

    return doDFS(0, size-1, k);
  }
};
