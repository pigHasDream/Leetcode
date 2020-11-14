class Solution {
  public:
  int minTotalDistance(vector<vector<int>>& grid) {
    
    // median is the shortest sum distance of 1-D problem.
    const int row = grid.size();
    const int col = grid.front().size();
    vector<int> rowPoint, colPoint;
    
    // get all the median points
    for(int i=0; i<row; ++i) {
      for(int j=0; j<col; ++j) {
        if(grid[i][j] == 1) {
          rowPoint.emplace_back(i);
          colPoint.emplace_back(j);
        }
      }
    }

    int rowMid = rowPoint[rowPoint.size()/2];
    nth_element(colPoint.begin(), 
                colPoint.begin()+colPoint.size()/2,
                colPoint.end());

    int colMid = colPoint[colPoint.size()/2];
    
    int res = 0;
    for(const auto& r : rowPoint)
      res += abs(r-rowMid);
    
    for(const auto& c : colPoint)
      res += abs(c-colMid);
    
    return res;
  }
};
