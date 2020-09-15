class Solution {
public:
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    // This is self solve
    // Key optimizaiton is to use index to map the string
    // This is not a Bi-BFS, nor using DFS to track the paths.
    
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if(dict.count(endWord) == 0) return {};
    
    const int wordLen = beginWord.size();
    // This maps the string to index vector
    // Use the index for intermediat solution and 
    // later construct the final string solution
    vector<string> mp(dict.begin(), dict.end());
    mp.emplace_back(beginWord);
    mp.emplace_back(endWord);
    const int dictLen = mp.size();
    const int dest = dictLen-1;
    const int start = dictLen-2;
    unordered_map<string,int> rmp;
    for(int i=0; i<dictLen; ++i) rmp[mp[i]] = i;
    
    vector<vector<int>> graph(dictLen);
    
    // Below instead of exhaustively checking each word pair
    // We alter each word char and use dict to see if it match up
    // This takes only O(N) time to finish
    for(int i=0; i<dictLen; ++i) {
      for(auto& c : mp[i]) {
        auto origChar = c;
        for(char newChar='a'; newChar<='z'; ++newChar) {
          if(newChar == origChar) continue;
          c = newChar;
          if(dict.count(mp[i])) {
            graph[i].emplace_back(rmp[mp[i]]);
          }
        }
        c = origChar;
      }
    }
    
    vector<int> visit(mp.size(), 0);
    queue<vector<int>> que;
    que.emplace(vector<int>{start});
    visit[start] = 1;
    
    vector<vector<int>> paths;
    bool found = false;
    
    while(not found and que.size()) {
      for(int k=que.size(); k>0; --k) {
        auto cur = que.front();
        que.pop();
        
        if(cur.back() == dest) {
          paths.emplace_back(cur);
          found = true;
          continue;
        }
        
        visit[cur.back()] = 1;
        for(const auto& nxt : graph[cur.back()]) {
          if(visit[nxt]) continue;
          cur.emplace_back(nxt);
          que.emplace(cur);
          cur.pop_back();
        }
      }
    }

    vector<vector<string>> res;
    if(not found) return res;
    
    for(const auto& path : paths) {
      vector<string> sol;
      for(const auto& node : path) {
        sol.emplace_back(mp[node]);
      }
      res.emplace_back(sol);
    }
    
    return res;
  }
};

