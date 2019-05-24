class Solution {
public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    
    unordered_set<string> front1, front2;
    unordered_set<string> wordHash(wordList.begin(), wordList.end());
    // this map is used to construct the final solution
    unordered_map<string, vector<string>> kids;
    
    if(not wordHash.count(endWord)) return {};
    front1.insert(beginWord);
    front2.insert(endWord);
    int len = beginWord.size();
    
    bool found(false);
    bool backward(false);
    while(front1.size() and front2.size() and not found) {
      // always work on the front1 and front1 will be small size
      if(front1.size() > front2.size()) {
        swap(front1, front2);
        backward = not backward; 
      }
      
      for(const auto& w : front1) wordHash.erase(w);
      for(const auto& w : front2) wordHash.erase(w);
      
      unordered_set<string> frontTmp;
      for(const auto& w : front1) {
        for(int i=0; i<len; ++i) {
          string cur = w;
          for(int k='a'; k<'z'; ++k) {
            cur[i] = k;
            string kid = cur;
            string parent = w;
            
            if(backward) swap(parent, kid);
            
            if(front2.count(cur)) {
              found = true;
              kids[parent].emplace_back(kid);
            }
            // we expand new word into the frontier only when not found!
            else if(not found and wordHash.count(cur)) {
              frontTmp.insert(cur);
              kids[parent].emplace_back(kid);
            }
          }
        }
      }
      swap(front1, frontTmp);
    }
    
    vector<vector<string>> res;
    if(found) {
      vector<string> curSol{beginWord};
      getPaths(beginWord, endWord, kids, curSol, res);
    }
    
    return res;
  }
  
  void getPaths(const string curWord, const string endWord,
                const unordered_map<string, vector<string>>& kids,
                vector<string>& curSol, vector<vector<string>>& res) {
    if(curWord == endWord) {
      res.emplace_back(curSol);
      return;
    }
    
    const auto out = kids.find(curWord);
    if(out == kids.cend()) return;
    
    for(const auto& kid : out->second) {
      curSol.emplace_back(kid);
      getPaths(kid, endWord, kids, curSol, res);
      curSol.pop_back();
    }
    
    return;
  }

};
