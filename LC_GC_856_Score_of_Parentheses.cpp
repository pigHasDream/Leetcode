class Solution {
public:
  int scoreOfParentheses(string S) {
    stack<int> stc;
    stc.emplace(0);
    
    for(const auto& c : S) {
      if(c == '(') {
        stc.emplace(0);
      }
      else {
        auto top = stc.top();
        stc.pop();
        
        int val = 0;
        if(top > 0) {
          val = top << 1;
        }
        else {
          val = 1;
        }
        stc.top() += val;
      }
    }
    
    return stc.top();
  }
};
