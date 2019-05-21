class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int left = matrix.front().front();
    int right = matrix.back().back();
    
    while(left < right) {
      int mid = left + (right - left)/2;
      
      int count = 0;
      for(const auto& row : matrix)
        count += distance(row.begin(), upper_bound(row.begin(), row.end(), mid));
      
      if(count >= k)
        right = mid;
      else 
        left = mid + 1;
    }
    
    return left;
  }
};
