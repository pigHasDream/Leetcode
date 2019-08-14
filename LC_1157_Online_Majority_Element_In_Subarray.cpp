class MajorityChecker {
  unordered_map<int, vector<int>> data_;
  
public:
  MajorityChecker(vector<int>& arr) {
    for(int i=0; i<arr.size(); ++i)   
      data_[arr[i]].emplace_back(i);
  }

  int query(int left, int right, int threshold) {
    for(const auto& p : data_) {
      if(p.second.size() < threshold) continue;
      
      // check for indexes' iterator position
      // also, everytime it goes over the unique value and check 
      // for each satisfying value.
      
      auto lit = lower_bound(p.second.begin(), p.second.end(), left);
      auto rit = upper_bound(p.second.begin(), p.second.end(), right);
      
      if(distance(lit, rit) >= threshold)
        return p.first;
    }
    return -1;
  }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
