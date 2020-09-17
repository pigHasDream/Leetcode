class Solution {
public:
  int minJumps(vector<int>& arr) {
    const int sz = arr.size();
    
    unordered_map<int,vector<int>> mp;
    
    for(int i=0; i<arr.size(); ++i) {
      mp[arr[i]].emplace_back(i);
    }
    
    queue<int> que;
    vector<int> visit(sz, 0);
    que.emplace(0);
    visit[0] = 1;
    
    int step = 0;
    while(que.size()) {
      for(int k=que.size(); k>0; --k) {
        auto top = que.front();
        que.pop();
        
        if(top == sz-1) return step;
        
        for(const auto& nxt : mp[arr[top]]) {
          if(visit[nxt]) continue;
          que.emplace(nxt);
          visit[nxt] = 1;
        }
        
        if(top >= 1 and visit[top-1] == 0) {
          que.emplace(top-1);
          visit[top-1] = 1;
        }
        
        if(top < arr.size()-1 and visit[top+1] == 0) {
          que.emplace(top+1);
          visit[top+1] = 1;
        }
 	       
        // This is needed to avoid LTE!
        mp.erase(arr[top]);
        
      }
      ++step;
    }

    return -1;
  }
};
