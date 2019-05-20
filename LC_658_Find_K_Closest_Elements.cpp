class Solution {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int left = 0, right = arr.size()-k;
    
    // Key thing is that we search the k range directly!
    // now we just need to determine the starting index, then
    // plus k elements.
    // mid refers to the starting position.
    // x-arr[mid] > arr[mid+k]-x means arr[mid]~arr[mid+k-1] is worse
    // than arr[mid+1]~arr[mid+k]. Here we can ignore all elements
    // between mid+1 ~ mid+k-1 as they are shared.
    
    while(left < right) {
      int mid = left + (right-left)/2;
      if(x-arr[mid] > arr[mid+k]-x) {
        left = mid+1;
      }
      else {
        right = mid;
      }
    }
    
    return vector<int>(left+arr.begin(), left+k+arr.begin());

  }
};
