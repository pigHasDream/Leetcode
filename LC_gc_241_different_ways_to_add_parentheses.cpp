class Solution {
public:
  vector<int> diffWaysToCompute(string input) {
    int sz = input.size();
    
    vector<vector<vector<int>>> memo(sz+1, vector<vector<int>>(sz+1));
    
    function<vector<int>(int,int)> doDFS = [&](int start, int end) {
      if(memo[start][end].size()) return memo[start][end];
      
      vector<int> res;
      
      bool foundOp = false;
      for(int i=start; i<=end; ++i) {
        if(input[i] == '+' or input[i] == '-' or input[i] == '*') {
          foundOp = true;
          break;
        }
      }
      
      if(foundOp) {
        vector<int> left;
        vector<int> right;

        for(int i=start+1; i<end; ++i) {
          if(input[i] == '+' or input[i] == '-' or input[i] == '*') {
            left = doDFS(start, i-1);
            right = doDFS(i+1, end);

            for(const auto& l : left) {
              for(const auto& r : right) {
                if(input[i] == '+') {
                  res.emplace_back(l + r);
                }
                else if(input[i] == '-') {
                  res.emplace_back(l - r);
                }
                else if(input[i] == '*') {
                  res.emplace_back(l * r);
                }
              }
            }
          }
        }
      }
      else {
        res.emplace_back(stoi(input.substr(start, end-start+1)));
      }
      
      return memo[start][end] = res;
      
    };
    
    
    return doDFS(0, sz-1);
  }
};
