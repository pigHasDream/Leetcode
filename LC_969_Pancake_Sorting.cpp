class Solution {
public:
  vector<int> pancakeSort(vector<int>& A) {
    int offset = 0;

    // each iteration ensure the smallest elem
    // of current range is in place!
    // like quick sort. So it'll gradually place 
    // all the elements  
    vector<int> res;
    
    while(offset < A.size()) {
      auto iter = max_element(A.begin(), A.end()-offset);
      int par = distance(A.begin(), iter);
      res.emplace_back(par+1);
      res.emplace_back(A.size()-offset);
      reverse(A.begin(), iter+1);
      reverse(A.begin(), A.end()-offset);
      ++offset;
    }

    return res;
  }
};
