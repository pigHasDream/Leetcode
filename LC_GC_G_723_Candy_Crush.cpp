class Solution {
public:
  vector<vector<int>> candyCrush(vector<vector<int>>& board) {
    const int row = board.size();
    const int col = board.front().size();
    const vector<int> dir{0,1,0,-1,0};
    
    auto convert = [&]() -> bool {
      bool found = false;

      for(int i=0; i<row; ++i) {
        for(int j=0; j<col-2; ++j) {
          int val = abs(board[i][j]);
          if(val == 0) continue;
          if(val == abs(board[i][j+1]) and val == abs(board[i][j+2])) {
            board[i][j] = board[i][j+1] = board[i][j+2] = -val;
            found = true; 
          }
        }
      }
      
      for(int j=0; j<col; ++j) {
        for(int i=0; i<row-2; ++i) {
          int val = abs(board[i][j]);
          if(val == 0) continue;
          if(val == abs(board[i+1][j]) and val == abs(board[i+2][j])) {
            board[i][j] = board[i+1][j] = board[i+2][j] = -val;
            found = true; 
          }
        }
      }

      return found;
    };


    // 2-pointers, slow pointer holds the position 
    // to convert to 0 all the way up.
    auto crush = [&]() -> void {
      
      for(int c=0; c<col; ++c) {
        int fast = row-1, slow = row-1;
        while(fast >= 0) {
          if(board[fast][c] > 0) {
            board[slow][c] = board[fast][c];
            --slow;
          }
          --fast;
        }
          
        while(slow >=0) {
          board[slow][c] = 0;
          --slow;
        }
      }
    };
    
    while(convert()) {
      crush();
    }
    
    return board;
  }
};
