// ------------------------------------------------------
// DFS approach. We monitor the min number of # to be removed.
class Solution {
public:
  vector<string> removeInvalidParentheses(string s) {
    int left = 0, right = 0;
    // This counts how many ( and ) need to be removed
    for(const auto& c : s) {
      left += c=='(';
      if(left == 0) 
        right += c==')';
      else
        left -= c==')';
    }
    
    vector<string> res;
    doDFS(s, 0, left, right, res);
    
    return res;
  }
  
  void doDFS(string s, int start, int left, int right, vector<string>& res) {
    if(left == 0 and right == 0) {
      if(isValid(s)) res.emplace_back(s);
      return;
    }
    
    for(int i=start; i<s.size(); ++i) {
      if(i!=start and s[i] == s[i-1]) continue;
      
      if(s[i] == '(' or s[i] == ')') {
        string cur = s;
        cur.erase(i,1);
        if(right>0 and s[i] == ')')
          doDFS(cur, i, left, right-1, res);
        else if(left>0 and s[i] == '(')
          doDFS(cur, i, left-1, right, res);
      }
    }
    return;
  }
  
  bool isValid(const string& s) {
    // check for () validness
    int count = 0;
    for(const auto& c : s) {
      if(c=='(') ++count;
      if(c==')') --count;
      if(count<0) return false;
    }
    return count == 0;
  }
};

// ---------------------------------------------------------
// BFS approach, more natural!

class Solution {
public:
  vector<string> removeInvalidParentheses(string s) {
    
    queue<string> que;
    unordered_set<string> visit;
    que.push(s);
    visit.insert(s);
    
    vector<string> res;
    
		// once we found the solution, we will not continue
    // to put more layers. We will just dump the current
    // que's elements.
    bool found(false);
    while(que.size()) {
      for(int i=que.size(); i>0; --i) {
        auto top = que.front();
        que.pop();
        
        if(isValid(top)) {
          res.emplace_back(top);
          found = true;
          continue;
        }
        
        if(not found) {
          for(int i=0; i<top.size(); ++i) {
            if(top[i]!='(' and top[i]!=')') continue;
            string next = top;
            next.erase(i,1);
            if(not visit.count(next)) {
              que.push(next);
              visit.insert(next);
            }
          }
        }
      }
    }
    
    return res;
  }
  
  bool isValid(const string& s) {
    // check for () validness
    int count = 0;
    for(const auto& c : s) {
      if(c=='(') ++count;
      if(c==')') --count;
      if(count<0) return false;
    }
    return count == 0;
  }
  
};
