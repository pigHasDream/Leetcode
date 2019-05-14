// Also see LC 664 strange printer!

class Solution {
  vector<vector<vector<int>>> memo_;
public:
  int removeBoxes(vector<int>& boxes) {
    int n = boxes.size();
    // 3D memo table stores from i to j bit, if there are k consecutive
    // bits following j and is the same as j.
    memo_.resize(n, vector<vector<int>>(n, vector<int>(n, -1)));
    
    return doDFS(boxes, 0, n-1, 0);
  }
  
  int doDFS(vector<int>& boxes, int left, int right, int k) {
    if(left > right) return 0;
    
    if(memo_[left][right][k] != -1) return memo_[left][right][k];
    
    // case1: directly take out the tailing k+1 elements.
    memo_[left][right][k] = doDFS(boxes, left, right-1, 0) + (k+1)*(k+1);
    
    // case2: optimal solution exists in partitioning between left and right
    // Then, we need to attach the tailing k+1 elements to the partition.
    // Note, the parition is meaningful only when the partition [i] has the same
    // color as the boxes[right]
    for(int i=left; i<=right-1; ++i) {
      if(boxes[i] == boxes[right]) {
        memo_[left][right][k] = max(memo_[left][right][k], doDFS(boxes, left, i, k+1) + doDFS(boxes, i+1, right-1, 0));
      }
    }
    
    return memo_[left][right][k];
  }
  
};
