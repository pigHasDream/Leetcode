
int doBinarySearch(int left, int right) {
  // Find the min index to satisfy g(index) == true
  // [left, right)
  // The template splits the array to 3 parts:
  // [0,mid), mid, [mid+1, size)
  
  while(left < right) {
    
    const int mid = left + (right - left)/2;

    // optional, find and return immediately
    // This one explicitly checks for [mid]
    if(f(mid)) return mid; 

    // if satisfy g(mid), continue getting the min one
    if(g(mid)) { 
      // do the right [left, mid)
      // This template is to find the min one satisfies 
      // g(mid), and we need to deal with right based on
      // the g(mid)
      right = mid;
    }
    else {
      // do the left [mid+1, right)
      left = mid+1; 
    }
  }

  return left; // or not found
}
       

int doBinarySearch(int left, int right) {
  // Find the min index to satisfy g(index) == true
  // [left, right]
  
  while(left <= right) {
    
    const int mid = left + (right - left)/2;

    // optional, find and return immediately
    // This one explicitly checks for [mid]
    if(f(mid)) return mid; 

    // if satisfy g(mid), continue getting the min one
    if(g(mid)) { 
      right = mid-1;
    }
    else {
      left = mid+1; 
    }
  }

  return left; // or right+1 for not found.
}
       
