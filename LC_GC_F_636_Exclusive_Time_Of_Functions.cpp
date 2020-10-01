class Solution {
  
public:
  vector<int> exclusiveTime(int n, vector<string>& logs) {
    
    vector<int> res(n, 0);
    stack<pair<int,int>> stc;
    
    for(const auto& line : logs) {
      int time = stoi(line.substr(line.rfind(':')+1));
      int id = stoi(line.substr(0,line.find(':')));
      
      bool isEnd = line[line.find(':')+1] == 'e';
      
      if(stc.empty()) {
        stc.emplace(id, time);
        continue;
      }
      // we always assume the top of stc if needed to pop,
      // is the same id with current one!
      // There is no overlaps!
      
      int delta = time - stc.top().second + 1;
      
      // the process is done at End case
      // Here we pop the top, and update the time duration.
      // Also, we need to subtract the same amount for the
      // new top stc element!!
      if(isEnd) {
        res[id] += delta;
        stc.pop();
        // Here is the key! we first subtract the values,
        // It can be negative!
        // But when pop it out, we add the length!
        if(stc.size()) {
          res[stc.top().first] -= delta;
        }
      }
      else {
        stc.emplace(id, time);
      }
    }
    
    return res;
  }
};
