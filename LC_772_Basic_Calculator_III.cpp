class Solution {
public:
  int calculate(string s) {
    
    long res = 0; 
    long num = 0;
    long curRes = 0;
    char op = '+';
    
    for(int i=0; i<s.size(); ++i) {
      if(isdigit(s[i])) {
        num = num*10 + (s[i] - '0');
      }
      else if(s[i] == '(') {
        int cnt = 0;
        int start = i;
        while(i<s.size()) {
          if(s[i] == '(') ++cnt;
          if(s[i] == ')') --cnt;
          if(cnt == 0) break;
          ++i;
        }
        num = calculate(s.substr(start+1, i-start-1));
      }
        
      if(s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/' or i == s.size()-1) {
        switch(op) {
          case '+' : curRes += num; break;
          case '-' : curRes -= num; break;
          case '*' : curRes *= num; break;
          case '/' : curRes /= num; break;
        }
        if(s[i] == '+' or s[i] == '-' or i == s.size()-1) {
          res += curRes;
          curRes = 0;
        }
        
        op = s[i];
        num = 0; 
      }
    }

    return res;
  }
};
