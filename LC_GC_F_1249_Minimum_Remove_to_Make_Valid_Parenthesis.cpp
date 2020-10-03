class Solution {
public:
  string minRemoveToMakeValid(string s) {
    stack<int> toRemove;
    
    for(int i=0; i<s.size(); ++i) {
      if(s[i] == '(') {
        toRemove.emplace(i);
      }
      else if (s[i] == ')') {
        if(toRemove.size() and s[toRemove.top()] == '(') {
          toRemove.pop();
        }
        else {
          toRemove.emplace(i);
        }
      }
    }
    
    while(toRemove.size()) {
      s[toRemove.top()] = '*';
      toRemove.pop();
    }
    
    s.erase(remove(s.begin(), s.end(), '*'), s.end());
    
    return s;
  }
};
