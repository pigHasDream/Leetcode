class Solution {
public:
  int maximumRequests(int n, vector<vector<int>>& requests) {
    unsigned int state = 0;
    int res = 0;
    const int sz = requests.size();
    
    vector<int> build(n, 0);
    
    auto isOK = [&]() {
      for(const auto& b : build) 
        if(b!=0) return false;
      return true;
    };

    function<void(int, unsigned)> doDFS = 
    [&](int idx, unsigned state) {
      if(idx == sz) {
        if(isOK()) {
          res = max(res, __builtin_popcount(state));
        }
        return;
      } 
      
      auto req = requests[idx];
      --build[req.front()];
      ++build[req.back()];
      doDFS(idx+1, state | (1<<idx));
      ++build[req.front()];
      --build[req.back()];
      
      doDFS(idx+1, state);
    };
    
    doDFS(0, 0);
    
    return res;
  }
};
