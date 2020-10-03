class Solution {
public:
  // Main thing is how to map the k/factor[n-1]
  // to the min available numbers!
  string getPermutation(int n, int k) {
    vector<int> nums(n,0);
    iota(nums.begin(), nums.end(), 1);
    
    vector<int> factor(n+1,1);
    for(int i=1; i<=n; ++i) 
      factor[i] = i*factor[i-1];
    
    // here we convert k to be 0 index based
    --k;
    string res;
      
    while(n>0) {
      // Key here is to map k/factor[n-1]
      // to the 12345..n sequence!
      // we start from the highest number.
      
      int pos = k/factor[n-1];
      res += char('0'+nums[pos]);
      
      k %= factor[n-1];
      
      // we keep removing the remaining numbers
      // Key is all the remaining numbers are in
      // sorted order, so that any k quotient will
      // point to the min available position!
      nums.erase(nums.begin() + pos);
      --n;
    }
     
    return res;
  }
};

