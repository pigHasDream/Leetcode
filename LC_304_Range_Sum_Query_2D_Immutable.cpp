class NumMatrix {
  vector<vector<int>> dp_;
  
public:
  NumMatrix(vector<vector<int>>& matrix) {
    int row = matrix.size();
    if(row==0) return;
    int col = matrix[0].size();
    if(col==0) return;
    
    dp_.resize(row+1, vector<int>(col+1, 0));
    
    for(int i=0; i<row; ++i) {
      for(int j=0; j<col; ++j) {
        dp_[i+1][j+1] = dp_[i+1][j] + dp_[i][j+1] - dp_[i][j] + matrix[i][j];
      }
    }
  }
    
  int sumRegion(int row1, int col1, int row2, int col2) {

    return dp_[row2+1][col2+1] - dp_[row1][col2+1] - dp_[row2+1][col1] + dp_[row1][col1];
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
