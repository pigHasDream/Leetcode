class Solution {
public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    
    int sz = s.size();
    unordered_map<int, vector<string>> memo;
    
    function<vector<string>(int)> doDFS =
      [&](int idx) -> vector<string> {
      
			// Key here is to use * marker to mark the end point!
      if(idx == sz) return {"*"};
      if(memo.count(idx)) return memo[idx];
      auto& ans = memo[idx];
      
      for(int len=1; len<=sz-idx; ++len) {
        string left = s.substr(idx, len);
        
        if(dict.count(left)) {
          auto ret = doDFS(idx+len);
				  // Below is the most triky part!
          // Problem is in case of idx == sz or no match found,
          // we need to distinguish these 2 cases.
          // Now, we artificially insert * to mark a match!
          // So, below will always have a match sequence
          // But, we need to pop out the star thing!
          for(auto& r : ret) {
            if(r.back() == '*')
              r.pop_back();
            ans.emplace_back(left + (r.size() ? " " + r : ""));
          }
        }
      }
      
      return ans;
    };
    
    return doDFS(0);
  }
};
