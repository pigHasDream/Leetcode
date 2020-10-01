//----------------------------------------------------
class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    
    vector<vector<int>> res;
    vector<int> curSol;
    
    function<void(int)> doDFS = [&](int idx) {
      if(idx > n) return;
      
      if(curSol.size() == k) {
        res.emplace_back(curSol);
        return;
      }
      
      for(int i=idx+1; i<=n; ++i) {
        curSol.emplace_back(i);
        doDFS(i);
        curSol.pop_back();
      }
      
    };
    
		// The number starts from 1, here we use 0 
    // becuase in the above loop, each i starts from
    // idx+1, so there is no duplication!
    // Therefore, we don't need to call visit
    doDFS(0);
    
    return res;
  }
};

//----------------------------------------------------
class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    
    vector<vector<int>> res;
    vector<int> curSol;
    vector<int> visit(n+1, 0);
    
    function<void(int)> doDFS = [&](int idx) {
      if(idx > n) return;
      
      if(curSol.size() == k) {
        res.emplace_back(curSol);
        return;
      }
      
      for(int i=idx; i<=n; ++i) {
        if(visit[i]) continue;
        visit[i] = 1;
        curSol.emplace_back(i);
        doDFS(i);
        curSol.pop_back();
        visit[i] = 0;
      }
      
    };
    
    // Here we need to call visit to remove the duplication,
    // This is because each time we start from i==idx.

    doDFS(1);
    
    return res;
  }
};


// =====================================================
// If no duplication result is expected. We do below:
class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    
    set<vector<int>> res;
    vector<int> curSol;
    int curSum = 0;
    const int sz = candidates.size();
    // To work together with the duplication removal procedure in DFS.
		// using set<vector<int>> can do the removal.
    sort(candidates.begin(), candidates.end());
    
    function<void(int)> doDFS = [&](int idx) {
      if(idx == sz) return;
      if(curSum > target) return;
      if(curSum == target) {
        res.emplace(curSol);
        return;
      }
      
      for(int i=idx+1; i<sz; ++i) {
        curSum += candidates[i];
        curSol.emplace_back(candidates[i]);
        doDFS(i);
        curSum -= candidates[i];
        curSol.pop_back();
      }
    };

    doDFS(-1);
    
    return vector<vector<int>>(res.begin(), res.end());
  }
};


// If no duplication result
class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    
    vector<vector<int>> res;
    vector<int> curSol;
    int curSum = 0;
    const int sz = candidates.size();
   // To work together with the duplication removal procedure in DFS.
    sort(candidates.begin(), candidates.end());
    
    function<void(int)> doDFS = [&](int idx) {
      if(curSum > target) return;
      if(curSum == target) {
        res.emplace_back(curSol);
        return;
      }
      
      for(int i=idx; i<sz; ++i) {
        // skip the same value AT THE SAME ITERATION!!
        if(i > idx and candidates[i] == candidates[i-1])
          continue;
        
        curSum += candidates[i];
        curSol.emplace_back(candidates[i]);
        doDFS(i+1);
        curSum -= candidates[i];
        curSol.pop_back();
      }
    };

    doDFS(0);
    
    return res;
  }
};
