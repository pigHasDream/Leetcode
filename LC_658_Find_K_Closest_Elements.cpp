class Solution {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    
    int low = 0, high = arr.size()-k;
    // consider a k+1 size window, and the bigger one must need to be
    // excluded. So the value x-arr[mid] and arr[mid+k]-x comparison
    // can be used to exclude which end is worse and that one can be 
    // excluded.
    
    while(low < high) {
      int mid = low + (high - low)/2;
      
      // if left end is bigger, this elem and its left half is invalid
      if(x-arr[mid] > arr[mid+k]-x) {
        low = mid+1;   
      }
      // if right end is bigger, and if left-right ends tie,
      // we discard the right end
      else {
        high = mid; 
      }
    }
    
    return vector<int>(arr.begin()+low, arr.begin()+high+k);
  }
};

