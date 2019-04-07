
int doBinarySearch(int left, int right) {
  
  // closed in left, open in right [left, right);
  while(left < right) {
    const int mid = left + (right - left)/2;

    if(f(mid)) return mid; // optional, find and return immediately just once by g(mid).

    if(g(mid) { // if satisfy, we continue to find the min one satisfying the g(mid)
      // do the right [left, mid)
      right = mid;
    }
    else {
      // do the left [mid+1, right)
      left = mid+1; 
    }
  }

  return left // or not found if we use f(mid) already!;
}

// Find the min index to satisfy g(index) ==true and return!!
