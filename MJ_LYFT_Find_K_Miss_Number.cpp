// Given a sorted vector, some numbers are missed.
// Return the k missed number.
// https://www.1point3acres.com/bbs/thread-525374-1-1.html

#include <iostream>
#include <vector>
using namespace std;

int getKthMiss(const vector<int>& vec, int k) {
  int left = 0, right = vec.size();
  int maxK = vec.back()-vec.front() - (vec.size()-1);
  if(k > maxK) return -1;
  
  // The stop condition must be left+1 < right
  // because we expect a range, so the left must 
  // be at least 1 smaller than right
  while(left+1 < right) {
    int mid = left + (right - left)/2;
    
    // This is the key! 
    // we find how many missed numbers between mid and left!
    int count = vec[mid] - vec[left] - (mid - left);
    
    if(count >= k) {
      right = mid;
    }
    else {
      // The left update is the same as mid 
      // because we use left+1<right as termination.
      left = mid;
      k -= count;
    }
    
  }
  
  return vec[left]+k;    
}


int main()
{
  vector<int> vec = {2,4,7,8,9,14,15};
  int numOfMiss = vec.back()-vec.front() - (vec.size());
  int extraForTesting = 10;
  
  for(int k=1; k<=numOfMiss + extraForTesting; ++k)
    cout << k << "   :     " << getKthMiss(vec, k) << endl;
    
  return 0;
}


