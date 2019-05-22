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



class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    
    auto cmp = [&matrix](const auto &p1, const auto &p2) {
      return matrix[p1.first][p1.second] > matrix[p2.first][p2.second];
    };
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> heap(cmp);
    
    heap.emplace(0,0);
    while(k-- > 1 and heap.size()) {
      auto top = heap.top();
      heap.pop();
      
      int i = top.first;
      int j = top.second;
      
      // This BFS based expansion is very similar to LC 373.
      if(j<n-1) heap.emplace(i, j+1);
      if(j==0 and i<n-1) heap.emplace(i+1, j);
    }
    
    return matrix[heap.top().first][heap.top().second];

  }
};
