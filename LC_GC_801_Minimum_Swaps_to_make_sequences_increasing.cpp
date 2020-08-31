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



// Memory improvement
class Solution {
public:
  int minSwap(vector<int>& A, vector<int>& B) {
    int keep = A.size();
    int change = A.size();
    int prev_keep = 0;
    int prev_change = 1;
    
    for(int i=1; i<A.size(); ++i) {
      // Note here we have to re-init the keep and change for 
      // each iteration!!
        
      keep = change = A.size();
      
      if(A[i] > A[i-1] and B[i] > B[i-1]) {
        keep = prev_keep;
        change = prev_change + 1;
      }
      
      if(A[i] > B[i-1] and B[i] > A[i-1]) {
        keep = min(keep, prev_change);
        change = min(change, prev_keep + 1);
      }
      
      // update the prev_value!!
      prev_change = change;
      prev_keep = keep;
    }
   
    return min(prev_keep, prev_change);

  }
};
