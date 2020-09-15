class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    
    sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
      if(a.front() == b.front()) 
        return a.back() < b.back();
      return a.front() < b.front();
    });
    
    for(const auto& interv : intervals) {
      if(res.empty() or res.back().back() < interv.front()) {
        res.emplace_back(interv);
      }
      else {
        res.back().back() = max(res.back().back(), interv.back());
      }
    }
    
    return res;
  }
};
