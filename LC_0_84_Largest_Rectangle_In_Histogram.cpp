class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    
    vector<int> num(heights);
		// Note here we have a 0 in the end
    num.emplace_back(0);
    stack<int> stc;
    
    int res = 0;
    for(int i=0; i<num.size(); ++i) {
      // monotonically increasing, when decreasing, process
      while(stc.size() and num[stc.top()] > num[i]) {
        auto top = stc.top();
        stc.pop();
        
        int width = i - (stc.empty() ? -1 : stc.top()) - 1;
        res = max(res, width*num[top]);
      }
      stc.push(i);
    }

    return res;
  }
};
