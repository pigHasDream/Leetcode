#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& vec, int left, int right) {
  int pivot = vec[left], l = left, r = right;
  
  while(l <= r) {
   // both l and r are opposite, swap them!
   if(vec[l]>pivot and vec[r]<pivot) 
     swap(vec[l++], vec[r--]);
   // l is ok, continue!
   else if(vec[l]<=pivot) 
     ++l;
   // r is ok, continue!
   else if(vec[r]>=pivot) 
     --r;
  }
  // swap the r with the pivot!
  swap(vec[left], vec[r]);
  
  // return the pivot's index
  return r;
}

void quickSort(vector<int>& vec, int left, int right) {
  if(left >= right) return;
  int mid = partition(vec, left, right);
  
  quickSort(vec, left, mid-1);
  quickSort(vec, mid+1, right);
}

int main()
{
  vector<int> vec{2,5,6,2,3,4,8,10,2,44};
  
  quickSort(vec, 0, vec.size()-1);
  
  for(const auto& e : vec)
    cout << e << " ";
  cout << endl;
  
  return 0;
}
