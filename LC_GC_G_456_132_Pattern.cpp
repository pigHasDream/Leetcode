class Solution {
public:
  bool find132pattern(vector<int>& nums) {
    
    stack<int> st;
    int size = nums.size();
    int prev = INT_MIN;
    
    for(int i=size-1; i>=0; --i) {
      if(prev > nums[i])
        return true;
      
      while(not st.empty() and st.top() < nums[i]) {
        prev = st.top();
        st.pop();
      }
      st.push(nums[i]);
    }
    
    return false;
  }
};
