class Solution {
public:
  string getPermutation(int n, int k) {
    // here we make a "visit" set
    vector<int> nums(n,0);
    iota(nums.begin(), nums.end(), 1);
    
    vector<int> factor(n+1,1);
    for(int i=1; i<=n; ++i) 
      factor[i] = i*factor[i-1];
    
    // here we convert k to be 0 index based
    --k;
    string res;
    
    while(n>0) {
      int pos = k/factor[n-1];
      res += char('0'+nums[pos]);
      
      k %= factor[n-1];
      
      nums.erase(nums.begin() + pos);
      --n;
    }
     
    return res;
  }
};


