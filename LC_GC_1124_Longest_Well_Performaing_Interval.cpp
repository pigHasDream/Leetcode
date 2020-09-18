class Solution {
public:
  int longestWPI(vector<int>& hours) {
    unordered_map<int,int> mp;
    
    int res = 0, sum = 0;
    for(int i=0; i<hours.size(); ++i) {
      // convert to 1, -1 case, and looking for sum=1 or all positive case. 
      sum += hours[i] > 8 ? 1 : -1;
      if(mp.count(sum)==0)
        mp[sum] = i;
      
      // if it's always positive, return the full length
      if(sum > 0) {
        res = max(res, i+1);
      }
      else {
        // else, if there is a sum-1, we use it.
        // No need to check sum-x, because this is a consecutive 1
        // Reason: if it's ever moved to negative territery, it must pass through
        // 1 and then goes to 0 and -1.
        // So it must have it.
        if(mp.count(sum-1)) {
          res = max(res, i-mp[sum-1]);
        }
      }
    }
    return res;
  }
};
