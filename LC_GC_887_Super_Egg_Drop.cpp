class Solution {
public:
  int superEggDrop(int K, int N) {
    vector<vector<int>> memo(K+1, vector<int>(N+1, -1));     

    function<int(int,int)> doDFS = [&] (int egg, int flr) {
		  // initial cases need to be careful
      if(egg == 0) return 0;
      if(egg == 1) return flr;
      if(flr <= 1) return flr;

      int& ans = memo[egg][flr];
      if(ans != -1) return ans;
      ans = N+1;

      for(int i=1; i<=flr; ++i) {
        int lower = doDFS(egg-1, i-1);
        int higher = doDFS(egg, flr-i);
        ans = min(ans, max(lower, higher) + 1);
      }
      
      return ans;
    };
    
    return doDFS(K, N);
  }
};




class Solution {
public:
  int superEggDrop(int K, int N) {
    vector<vector<int>> memo(K+1, vector<int>(N+1, -1));     

    function<int(int,int)> doDFS = [&] (int egg, int flr) {
      if(egg == 0) return 0;
      if(egg == 1) return flr;
      if(flr <= 1) return flr;

      int& ans = memo[egg][flr];
      if(ans != -1) return ans;
      ans = N+1;
      
      int left = 0; int right = flr+1;
      
		 // Here instead of scanning all i
     // it uses monotone nature
      while(left < right) {
        int mid = left + (right -left)/2;
        int broken = doDFS(egg-1, mid-1);
        int unbroken = doDFS(egg, flr-mid);
        if(broken >= unbroken) right = mid; 
        else left = mid+1;
      }
      
      // there might be a step glitch,
      // so safer way is to do a final max!
      ans = 1 + max(doDFS(egg, flr-left), doDFS(egg-1, left-1));
        
      return ans;
    };
    
    return doDFS(K, N);
  }
};
