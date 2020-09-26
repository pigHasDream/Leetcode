class Solution {
public:
  int findKthPositive(vector<int>& arr, int k) {
    
    //arr[i]: 2 3 4 7 11
    //     i: 0 1 2 3 4
    // miss : 1 1 1 3 6
    //
    // key thing is the realization of
    // arr[i] - (i+1) refers to the missed number counts!
    
    for(int i=0; i<arr.size(); ++i) {
      if(arr[i] - (i+1) >= k) {
        // the missed number covers the k
        return i+k;
      }
    }

    // the arr is too short, need to extend further
    return arr.size()+k;
  }
};



class Solution {
public:
  int findKthPositive(vector<int>& arr, int k) {
    
    //arr[i]: 2 3 4 7 11
    //     i: 0 1 2 3 4
    // miss : 1 1 1 3 6
    
    int left = 0, right = arr.size();
    
    while(left < right) {
      int mid = left + (right-left)/2;
      
      if(arr[mid] - (mid+1) >= k) {
        right = mid; 
      }
      else {
        left = mid+1;
      }
    }
    
    /*
    We use binary search to find the smallest index, l, 
    *such that there are at least k missing numbers in [0, A[l]].*
    
    The actual number of missing numbers in [0, A[l-1]] is A[l-1] - (l - 1) - 1 = A[l-1] - l. 
    Counting from A[l-1], The k-th missing number is therefore (A[l-1] + k - (A[l-1] - l) = l + k
    */

    return right + k;
  }
};
