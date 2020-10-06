class Solution {
public:
  int minSwap(vector<int>& A, vector<int>& B) {
    
    int sz = A.size();
    // Init to maximum 
    vector<int> keep(sz, sz);
    vector<int> change(sz, sz);
    // initial 0 position keep is 0,
    // change is 1 as we will need to swap
    keep.front() = 0;
    change.front() = 1;
    
    // start with 1
    for(int i=1; i<sz; ++i) {
      // if current idx and prev are already ok
      // for both A and B
      // We'll need to keep the relation:
      // either swap together with prev or not swap

      if(A[i] > A[i-1] and B[i] > B[i-1]) {
        keep[i] = keep[i-1];
        change[i] = change[i-1] + 1;
      }
      
      // NOTE! here we just do further check on top
      // of the earlier if-branch.
      // It could happen when both if-branches meet
      // And the order of checking which one first doesn't matter.


      // prev and current relation has to be swapped.

      if(A[i] > B[i-1] and B[i] > A[i-1]) {
        keep[i] = min(keep[i], change[i-1]);
        change[i] = min(change[i], keep[i-1] + 1);
      }
    }

    return min(keep.back(), change.back());
  }
};



// Memory efficient approach needs to re-init the current value
// and update the previous value!!

class Solution {
public:
  int minSwap(vector<int>& A, vector<int>& B) {
    const int inf = 1001;
    int prev_swap = 1, prev_keep = 0;
    int curr_swap = inf, curr_keep = inf;
    
    for(int i=1; i<A.size(); ++i) {

      // Note here we have to re-init
      // the curr_keep and curr_swap

      curr_keep = inf;
      curr_swap = inf;
      
      if(A[i] > A[i-1] and B[i] > B[i-1]) {
        curr_keep = prev_keep;
        curr_swap = prev_swap + 1;
      }
      
      if(A[i] > B[i-1] and B[i] > A[i-1]) {
        curr_keep = min(curr_keep, prev_swap);
        curr_swap = min(curr_swap, prev_keep+1);
      }
      
      prev_keep = curr_keep;
      prev_swap = curr_swap;
    }

    return min(curr_keep, curr_swap);
  }
};


