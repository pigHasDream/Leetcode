class Solution {
public:
  int longestWPI(vector<int>& hours) {
    
    unordered_map<int, int> hash;
    
    int res = 0;
    for(int i=0, sum=0; i<hours.size(); ++i) {
      // convert it to 1, -1 longest target sum 1!
      // we only need 1 more to satisfy!
      sum += hours[i] > 8 ? 1 : -1;
      
      // when prefix sum > 0, it must be the solution
      // all the way to the 0-th idx
      if(sum > 0) {
        res = max(i+1, res);
      }
      else {
        // if prefix sum < 1, we need earlier prefix sums
        // to get subtracted down.
        // the target is sum-1, because, sum-1 is the best
        // case, sum-2 (target = 2) is not needed to be checked,
        // because this is a consecutive sequence, if you have 2,  
        // you will definitely get 1.
        // This step is a GREEDY manner!
        if(hash.count(sum-1)) {
          res = max(res, i - hash[sum-1]);
        }
      }
      
      // put in only the first index of a sum.
      if(not hash.count(sum))
        hash[sum] = i;
    }

    return res;
  }
};
