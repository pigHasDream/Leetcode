class Solution {
public:
  vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
    sort(A.begin(), A.end());
    double left= 0.0, right= 1.0;
    vector<int> res;
    
    while(left < right) {
      double mid = (left+right)/2.0;
      
      int count = 0;
      double maxFrac = 0;
      res.resize(2, -1);
      for(int start=0, end=0; start<A.size(); ++start) {
        while(end<A.size() and double(A[start]) > mid*double(A[end])) ++end;
        count += A.size()-end;
        
        if(end < A.size()) {
          double ratio = double(A[start])/double(A[end]);
          if(maxFrac < ratio) {
            maxFrac = ratio;
            res = {A[start], A[end]};
          }
        }
      }
      
      // For those floating type binary search
      // we can have a separate termination condition
      // and then the left and right bounds are assigned
      // to mid directly!!
      if(count == K) break;
      else if(count > K) right = mid;
      else left = mid;
    }

    return res;
  }
};
