// Union Find solution
class Solution {
public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    
    unordered_map<string, string> parent;
    unordered_map<string, string> em2name;

    function<const string&(const string&)> find = [&](const string& em) -> const string& {
      if(parent[em] != em) {
        parent[em] = find(parent[em]);
      }
      return parent[em];
    };
    
    for(const auto& acc : accounts) {
      string name;
      for(int i=0; i<acc.size(); ++i) {
        if(i==0) name = acc[i];
        else {
          if(i==1) em2name[acc[i]] = name;
          if(parent.count(acc[i]) == 0) parent[acc[i]] = acc[1];
          else parent[find(acc[i])] = parent[acc[1]];
        }
      }
    }
    
    unordered_map<string, set<string>> mres;
    for(const auto& pr : parent)
      mres[find(pr.first)].emplace(pr.first);
    
    vector<vector<string>> res;
    for(const auto& m : mres) {
      vector<string> row;
      row.emplace_back(em2name[m.first]);
      for(const auto& ems : m.second) {
        row.emplace_back(ems);
      }
      res.emplace_back(row);
    }
    
    return res;
  }
};


// DFS solution
// No need to add all edges among all email nodes
// only need to use representative email as root to connect all emails within a group
// In that sense, this is pretty much the same as Union-Find solution as there is only one root!

class Solution {
  
public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
      
    unordered_map<string, unordered_set<string>> graph;
    
    // create the graph
    for(const auto& p : accounts) {
      for(int i=1; i<p.size(); ++i) {
        graph[p[1]].emplace(p[i]);
        graph[p[i]].emplace(p[1]);
      }
    }
    
    vector<vector<string>> res;
    unordered_set<string> visit;
    
    function<void(string,const string&,vector<string>&)> 
      doDFS = [&](string name, const string& curEm, vector<string>& curRow) {
      if(visit.count(curEm)) return;
      
      if(name.size()) {
        curRow.emplace_back(name);
        name.clear();
      }
      
      curRow.emplace_back(curEm);
      visit.emplace(curEm);
      
      for(const auto& next : graph[curEm]) {
        doDFS(name, next, curRow);
      }
    };
      
    for(const auto& acc : accounts) {
      vector<string> curR;
      doDFS(acc.front(), acc.back(), curR);
      if(curR.size())
        res.emplace_back(curR);
    }
    
    for(auto& row : res)
      sort(row.begin()+1, row.end());
    
    return res;
  }
};

