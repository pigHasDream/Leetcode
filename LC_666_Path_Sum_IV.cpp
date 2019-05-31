class Solution {
public:
  int pathSum(vector<int>& nums) {
    
    // Key here is to accumulate like prefixSum
    // for each node when creating!
    unordered_map<int, unordered_map<int, int>> hash;
    for(const auto& n : nums) {
      int i = n/100;
      int j = (n/10)%10;
      int k = n%10;
      
      hash[i][j] = hash[i-1][(j+1)/2] + k;
    }
    
    int res=0;
    // Now, we only sum up the leaf nodes!
    for(int i=4; i>0; --i) {
      for(int j=(1<<(i-1)); j>0; --j) {
        res += hash[i][j] and !hash[i+1][j*2] and !hash[i+1][j*2-1] ? hash[i][j] : 0;
      }
    }

    return res;
  }
};


