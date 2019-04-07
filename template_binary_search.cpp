
int doBinarySearch(int left, int right) {
  
  // closed in left, open in right
  while(left < right) {
    const int mid = left + (right - left)/2;

    if(check(mid)) return mid; // optional

    if(proceedInLeft) {
      // do the right [left, mid)
      right = mid;
    }
    else {
      // do the left [mid+1, right)
      left = mid+1; 
    }
  }

  return left or not found;
}
