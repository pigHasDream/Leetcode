class Solution {
public:
  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    if(startFuel >= target) return 0;
    
    const int sz = stations.size();
    // total fuel
    priority_queue<int> que;
    que.emplace(startFuel);
    
    int stationIdx = 0;
    int totalFuel = 0;
    int res = 0;
    
    while(que.size()) {
      auto fuel = que.top();
      que.pop();
      
      totalFuel += fuel;

      if(totalFuel >= target) return res;

      while(stationIdx < sz and stations[stationIdx].front() <= totalFuel) {
        que.emplace(stations[stationIdx].back());
        ++stationIdx;
      }
      
      ++res;
    }
    
    return -1;
  }
};
