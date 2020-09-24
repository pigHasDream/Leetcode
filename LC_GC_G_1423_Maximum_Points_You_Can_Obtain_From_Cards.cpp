class Solution {
public:
  int maxScore(vector<int>& cardPoints, int k) {
    const int sz = cardPoints.size();
    
    // Key observation is the final results are coming
    // from a rotated k-length segment in the array.
    // 2 1 4 5 6 1 3 2 4 6 1
    
    int sum = 0;
    for(int i=0; i<k; ++i) 
      sum += cardPoints[i];
     
    int res = sum;
    for(int i=k-1, j=1; i>=0; --i, ++j) {
      sum += cardPoints[sz-j] - cardPoints[i];
      res = max(res, sum);
    }

    return res;
  }
};
