class Solution {
public:
  vector<string> removeInvalidParentheses(string s) {
    int sz = s.size();
    vector<string> res;
    
    // Use greedy approach to get the final maxLen
    // the min removal will be the same as 
    int count = 0, toRemove = 0;
    for(const auto& c : s) {
      if(c=='(') ++count;
      else if(c==')') --count;
      if(count < 0) {
        count = 0;
        ++toRemove;
      }
    }
    toRemove += count;
    
    // here gets the final results
    // we just need to meet with the same length
    int maxLen = sz-toRemove;
    
    function<void(int,string,int)> doDFS
      =[&](int idx, string curSol, int count) {
      if(count < 0) return;
      if(curSol.size() > maxLen) return;
      if(idx == sz) {
        if(curSol.size()==maxLen and count==0) {
          res.emplace_back(curSol);
        }
        return;
      }
      
      // BELOW is the key trick to remove the duplications!
      // we compare the last letter of curSol with s[idx],
      // if they are the same, we MANDATE to add a new letter!
      // otherwise, we can skip the adding new letter!
      //  if(curSol.back() == s[idx]) doDFS(curSol+s[idx])
      //  if(curSol.back() != s[idx]) doDFS(curSol+s[idx]), doDFS(curSol);
      // we can merge above 2 cases!
      // This is intuitively to enforce adding the letter as long as
      // we hit a same letter of previous results!
      // Because, we can always use the last letters to get result.
      // It reduces the use of set to remove duplications!
      if(s[idx] == '(' or s[idx] == ')') {
        doDFS(idx+1, curSol+s[idx], count + (s[idx]=='(' ? 1 : -1));
        if(curSol.empty() or curSol.back() != s[idx])
          doDFS(idx+1, curSol, count);
      }
      else {
        doDFS(idx+1, curSol+s[idx], count);
      }
    };
    
    doDFS(0,"",0);

    return res;
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


// ---------------------------------------------------------
// BFS approach better
// KEY: this is a combination problem: keep or remove a char 
// from the original stirng.
// Therefore, the visit check can be saved by using an index
// keeper. So we push que a pair with index.
// Now, By doing that, we can further skip the neighboring 
// 2 chars with the same value, so it won't need to be put.
class Solution {
public:
  vector<string> removeInvalidParentheses(string s) {
    // OPT 1
    // book keep the start index, so 
    // we never re-visit from the same place
    // This can save the use of visit hash!!
    // This is a combination problem not permutation!
    // Therefore, we can use index to avoid duplication!
    queue<pair<string,int>> que;
    que.emplace(s,0);
    
    vector<string> res;
    
    auto isValid = [&](const auto& str) {
      int count = 0;
      for(const auto& c : str) {
        if(c=='(') ++count;
        else if(c==')') --count;
        if(count < 0) return false;
      }
      return count == 0;
    };
    
    bool found = false;
    while(que.size()) {
      for(int k=que.size(); k>0; --k) {
        auto [str, idx] = que.front();
        que.pop();
        
        if(isValid(str)) {
          found = true;
          res.emplace_back(str);
          continue;
        }
        
        if(not found) {
          for(int i=idx; i<str.size(); ++i) {
            if(str[i]!='(' and str[i]!=')') continue;
            
            // OPT 2
            if(i!=idx and str[i] == str[i-1]) continue;
            
            auto nxt = str;
            nxt.erase(i, 1);
            que.emplace(nxt, i);
          }
        }
      }
    }
    
    return res;
  }
};
