class Solution {
  
public:
  int shortestWay(string source, string target) {
    vector<vector<int>> hash(26, vector<int>(0));
    int res = 0;
    for(int k=0; k<source.size(); ++k)
      hash[source[k]-'a'].emplace_back(k);
    
    for(int i=0, j=-1; i<target.size();) {
      auto tar = hash[target[i]-'a'];
      if(tar.empty()) return -1;
      auto iter = upper_bound(tar.begin(), tar.end(), j);
      if(iter != end(tar)) {
        j=*iter, ++i;
      }
      else {
        ++res, j=-1;
      }
    }
    
    return res+1;
  }
  
};
