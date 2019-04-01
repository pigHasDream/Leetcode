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
