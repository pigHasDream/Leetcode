class Solution {
public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    
    vector<vector<int>> res;
    vector<int> curSol;
    
    function<void(int)> doDFS = [&] (int idx) {
      if(curSol.size()>1)
        res.emplace_back(curSol);
      
      if(idx == nums.size()) return;
      
      // duplication only happens in the same LEVEL!!
      // either use a unordered_set to check AT THIS LEVEL!
      unordered_set<int> uniq;
      for(int i=idx; i<nums.size(); ++i) {
        if(curSol.size() and curSol.back() > nums[i])
          continue;
        
        // This is very important!!!!!!!
        // It records the same element used at the SAME LEVEL!
        // This avoids the duplications!
        if(uniq.count(nums[i])) continue;
        uniq.emplace(nums[i]);
        
        curSol.emplace_back(nums[i]);
        doDFS(i+1);
        curSol.pop_back();
      }
    };
    
    doDFS(0);
    
    return res;
  }
};



