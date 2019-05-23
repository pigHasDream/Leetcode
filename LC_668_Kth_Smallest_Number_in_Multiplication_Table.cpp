class Solution {
public:
  int findKthNumber(int m, int n, int k) {
    long left=0, right=m*n+1; 
    
    while(left < right) {
      long mid = left + (right-left)/2;
      
      int count = 0;
      // since the matrix is sorted,
      // we can use 2 pointers: the j can
      // start from right most and due 
      // to monotonic nature, j does not
      // need to start from rightmost always!
      for(int i=1, j=n; i<=m; ++i) {
        while(j>=1 and i*j > mid) --j;
        count += j; 
      }
      
      if(count >= k) right = mid;
      else left = mid+1;
    }
    
    return left;
  }
};
