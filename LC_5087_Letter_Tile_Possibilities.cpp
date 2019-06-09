class Solution {
public:
  int numTilePossibilities(string tiles) {
    unordered_set<string> res;
    
    function<void(int, string)> doDFS = [&](int used, string cur) {
      res.emplace(cur);
      
      for(int i=0; i<tiles.size(); ++i) {
        if((1<<i) & used) continue;
        doDFS(used | (1<<i), cur+tiles[i]);
      }
    };
    
    doDFS(0, "");
    return res.size()-1;
  }
  
};
