class Solution {
public:
  struct State {
    string str="";
    int len=0;
    int x=-1;
    int y=-1;
    
    bool operator() (const State& s1, const State& s2) {
      if(s1.len != s2.len)
        return s1.len > s2.len;
      else
        return s1.str > s2.str;
    }
  };

  string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
    set<pair<int, int>> visited;
    
    const map<char, pair<int, int>> dir {
      {'u', {-1, 0}},
      {'d', {1, 0}},
      {'l', {0, -1}},
      {'r', {0, 1}}
    };
    
    priority_queue<State, vector<State>, State> que;
    
    int row = maze.size();
    int col = maze[0].size();
    que.push({"", 0, ball[0], ball[1]});
    
    while(que.size()) {
      
      auto top = que.top();
      que.pop();

      string curString = top.str;
      int x = top.x;
      int y = top.y;
      int len = top.len;

      if(x == hole[0] and y == hole[1]) {
        return curString;
      }

      if(visited.find({x,y}) != visited.end())
        continue;

      visited.insert({x,y});

      for(auto const& d : dir) {

        int newX = x;
        int newY = y;
        bool foundNew(false);
        int addCount = 0;
        
        while(check(newX + d.second.first, newY + d.second.second, row, col, maze)) {
          foundNew = true;
          newX += d.second.first;
          newY += d.second.second;
          ++addCount;
          if(newX == hole[0] and newY == hole[1])
            break;
        }

        if(foundNew) {
          que.push({curString + string(1, d.first), len+addCount, newX, newY});
        }

      }
    }
    
    return "impossible";
  }
  
  bool check(int a, int b, int row, int col, const vector<vector<int>>& maze) {
    return a>=0 and a<row and b>=0 and b<col and maze[a][b] != 1;
  }
};
