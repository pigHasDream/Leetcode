class Solution {
public:
  int sumSubarrayMins(vector<int>& A) {
    const int mod = 1e9+7;
    int size = A.size();
    vector<int> left(size, -1), right(size, size);
    stack<int> leftStack, rightStack;
    
    for(int i=size-1; i>=0; --i) {
      // left side min range
      while(not leftStack.empty() and A[leftStack.top()] > A[i]) {
        left[leftStack.top()] = i;
        leftStack.pop(); 
      }
      leftStack.push(i);
    }
    
    for(int i=0; i<size; ++i) {
      while(not rightStack.empty() and A[rightStack.top()] >= A[i]) {
        right[rightStack.top()] = i;
        rightStack.pop(); 
      }
      rightStack.push(i);
    }
    
    long res = 0;
    for(int i=0; i<size; ++i) {
      res = A[i]*(i-left[i])*(right[i]-i) % mod + res;
      res %= mod; 
    }
      
    return res;
  }
};
