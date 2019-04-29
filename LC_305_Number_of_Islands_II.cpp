class Solution {
  vector<int> grid_;
public:
  vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
    int size = positions.size();
    vector<int> res;
    if(size == 0) return res;
    
    // use -1 as the water or invalid state
    grid_.resize(m*n, -1);
    
    vector<int> dir{0,1,0,-1,0};
    int count = 0;
    
    for(const auto& pos : positions) {
      int i = pos[0];
      int j = pos[1];
      
      int id = i*n + j;
      // if currently is water, now, convert it to island
      // increase the count by 1. It may get reversed later.
      if(grid_[id] == -1) {
        grid_[id] = id;
        ++count;
      }
      
      int curr = find(id);
      
      for(int k=0; k<4; ++k) {
        int xx = i + dir[k];
        int yy = j + dir[k+1];
        int nId = xx*n + yy;
        
        if(xx<0 or xx>m-1 or yy<0 or yy>n-1 or grid_[nId] == -1)
          continue;
        
        int next = find(nId);
				// each consecutive node if they are not the same parent,
        // merge them, and reduce one count.
        if(curr != next) {
          grid_[next] = curr;
          --count; 
        }
      }
      res.emplace_back(count);
    }
    return res;
  }

private:
  int find(int u) {
    if(grid_[u] != u) {
      grid_[u] = find(grid_[u]);
    }
    return grid_[u];
  }
  
};
