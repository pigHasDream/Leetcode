class Solution {
public:
  string removeKdigits(string num, int k) {
    
    int size = num.size();
    int keep = size-k;
    // use res directly as the stack
    string res{""};
    
    for(int i=0; i<size; ++i) {
      while(!res.empty() and res.back() > num[i] and k > 0) {
        res.pop_back();
        --k;
      }
      res.push_back(num[i]);
    }
    
    res.resize(keep);
    
    while(!res.empty() and res[0] == '0')
      res.erase(res.begin());
    
    return res.empty() ? "0" : res;

  }
};
