//----------------------------------------------------
class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {

    vector<vector<int>> res;
    vector<int> move;
    unordered_set<int> hash;
    
    // return all permutations
    // starts with empty move
    // actual fills start inside backTrace
    recurBackTrace(nums, hash, move, res);
    
    return res;
  }
  
private:
  void recurBackTrace(const vector<int>& nums, 
                      unordered_set<int>& hash, 
                      vector<int>& move, 
                      vector<vector<int>>& res) {
    
    if(move.size() == nums.size()) {
      res.emplace_back(move);
      return;
    }
    
    for(int i=0; i < nums.size(); ++i) {
      if(hash.count(nums[i])) continue;
       
      move.emplace_back(nums[i]);
      hash.insert(nums[i]);
      
      recurBackTrace(nums, hash, move, res);
      
      move.pop_back();
      hash.erase(nums[i]);
    }
  }
  
};

//----------------------------------------------------
class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    
    vector<vector<int>> res;
    vector<int> curSol;
    vector<int> visit(nums.size(), 0);
    
    function<void()> doDFS = [&](){
      if(curSol.size() == nums.size()) {
        res.emplace_back(curSol);
        return;
      }
      
      for(int i=0; i<nums.size(); ++i) {
        if(visit[i]) continue;
        
        visit[i] = 1;
        curSol.emplace_back(nums[i]);
        doDFS();
        curSol.pop_back();
        visit[i] = 0;
      }
    };
    
    doDFS();
    
    return res;
  }
};
