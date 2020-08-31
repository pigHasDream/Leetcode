class Solution {
  const vector<pair<int, int>> dir_ = {{-1,0}, {0,1}, {1, 0}, {0,-1}};
  set<pair<int,int>> visited_;
  
public:
  void cleanRoom(Robot& robot) {
    doDFS(robot, 0, 0, 0);
  }
  
  void doDFS(Robot& robot, int x, int y, int facing) {
    
    robot.clean();
    visited_.insert({x,y});
    
    for(int i=0; i<4; ++i) {
      int newFacing = (facing+i) & 3;
      
      int xx = x + dir_[newFacing].first;
      int yy = y + dir_[newFacing].second;
      
      if(visited_.find({xx,yy}) == visited_.end() and robot.move()) {
        doDFS(robot, xx, yy, newFacing);
        
        robot.turnLeft();
        robot.turnLeft();
        robot.move(); 
        robot.turnLeft();
        robot.turnLeft();
      }
      
      robot.turnRight();
    }
  }
  
};




class Solution {
public:
  void cleanRoom(Robot& robot) {
    
    unordered_map<int,unordered_map<int, int>> visit;
    vector<int> dir{0,1,0,-1,0};
    int face = 0;
    
    function<void(int,int,int)> doDFS = 
      [&](int x, int y, int face) -> void {
      
      if(visit[x][y])
        return;
        
      visit[x][y] = 1;
      robot.clean();
      
      for(int k=0; k<4; ++k) {
        int xx = x + dir[face%4];
        int yy = y + dir[(face+1)%4];
        
        // keep the original facing when exit
        if(robot.move()) {
        
          doDFS(xx, yy, face);
          robot.turnRight();
          robot.turnRight();
          robot.move();
          robot.turnLeft();
          robot.turnLeft();
          
        }
        
        robot.turnRight();
        face = (face+1)%4;
      }
    };
    
    doDFS(0,0,0); 
  }
};
