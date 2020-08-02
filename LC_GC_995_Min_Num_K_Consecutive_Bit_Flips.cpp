class Solution {
public:
  int minKBitFlips(vector<int>& A, int K) {
    // Two intuitions:
    // 1. if we check for each individual elem, if it's 0, it mst be flipped
    //    And even num of flips is no-op. We have to flip just min number.
    //    It also does not matter the order of flips in the sequence.
    // 2. We can use a sliding queue to record the elems in current queue, 
    //    This is good for doing the odd/even check much quickly.
    
    queue<int> que;
    int res = 0;
    for(int i=0; i<A.size(); ++i) {
      if(que.size() and (que.front() + K <= i)) {
        que.pop();
      }
      
      if((que.size() + A[i])%2 == 0) {
        if(i+K > A.size()) 
          return -1;
        else {
          ++res;
          que.emplace(i);
        }
      }
    }
    
    return res;
  }
};
