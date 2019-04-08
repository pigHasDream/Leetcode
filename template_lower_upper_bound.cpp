
#include <iostream>
#include <vector>
using namespace std;
 
// [left, right)
// Binary search: find the min value satisfy the predicate!
int upper_bound(const vector<int>& A, int val, int l, int r) {
  while (l < r) {
    // l + (r-l)/2 is to avoid possible overlow!
    int m = l + (r - l) / 2;
    if (A[m] > val) 
     r = m;
    else      
      l = m + 1;
  }
  return l;
}
 
int lower_bound(const vector<int>& A, int val, int l, int r) {
  while (l < r) {
    int m = l + (r - l) / 2;
    if (A[m] >= val)
      r = m;
    else
      l = m + 1;
  }
  return l;
}
 
int main() {
  vector<int> A{1, 2, 2, 2, 4, 4, 5};
  cout << lower_bound(A, 0, 0, A.size()) << endl; // 0
  cout << lower_bound(A, 2, 0, A.size()) << endl; // 1
  cout << lower_bound(A, 3, 0, A.size()) << endl; // 4
  cout << upper_bound(A, 2, 0, A.size()) << endl; // 4
  cout << upper_bound(A, 4, 0, A.size()) << endl; // 6
  cout << upper_bound(A, 5, 0, A.size()) << endl; // 7
}

