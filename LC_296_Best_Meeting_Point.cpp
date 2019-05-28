class Solution {
public:
  int minTotalDistance(vector<vector<int>>& grid) {
    int n = grid.size();
    if(n==0) return 0;
    int m = grid[0].size();
    if(m==0) return 0;
    
    vector<int> vert;
    vector<int> hori;
    
    for(int i=0; i<n; ++i){
      for(int j=0; j<m; ++j) {
        if(grid[i][j]) vert.emplace_back(i);
        if(grid[i][j]) hori.emplace_back(j);
      }
    }
    
    return findManhattanDist(vert) + findManhattanDist(hori);
  }
  
  int findManhattanDist(vector<int>& vec) {
    sort(vec.begin(), vec.end());
    int i=0, j=vec.size()-1;
    int dist = 0;
    while(i<j) dist += vec[j--] - vec[i++];
    return dist; 
  }
  
};
