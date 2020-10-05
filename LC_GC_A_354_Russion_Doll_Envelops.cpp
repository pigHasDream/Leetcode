class Solution {
public:
  int maxEnvelopes(vector<vector<int>>& env) {
    
    sort(env.begin(), env.end(), [](const auto& a, const auto& b) {
      // If front is the same, we must sort reversely for the back!
      // Reason is this would makes the later greedy search natually
      // consistent!!
      if(a.front() == b.front()) return a.back() > b.back();
      return a.front() < b.front(); 
    });
    
    const int sz = env.size();
    vector<int> res;
    
    for(const auto& pair : env) {
      auto iter = lower_bound(res.begin(), res.end(), pair.back());
      if(iter != res.end()) *iter = pair.back();
      else res.emplace_back(pair.back());
    }
    
    return res.size();
  }
};
