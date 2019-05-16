class Solution {
  vector<int> sum_;
  vector<vector<int>>& rect_;
  
  int getRand(int n) {
    return rand()%n;
  }
  
public:
  Solution(vector<vector<int>>& rects) : rect_(rects) {
		// similar to 528, use prefix sum to accumulate the rectangle's areas.
    // Then, sampling number in range of [0, totalArea].
    // Then find the corresponding index holding the area.
    // Then do another sample to get the random point in the specified 
    // rectangle.
    sum_.resize(rects.size());
    for(int i=0; i<rects.size(); ++i) {
      sum_[i] = (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
      if(i>0) sum_[i] += sum_[i-1];
    }
  }

  vector<int> pick() {
    
    // first sample
    int val = getRand(sum_.back());
    auto id = upper_bound(sum_.begin(), sum_.end(), val) - sum_.begin();
    
    // another level of sample
    return { rect_[id][0] + getRand(rect_[id][2] - rect_[id][0] + 1),
             rect_[id][1] + getRand(rect_[id][3] - rect_[id][1] + 1) };
  }
  
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
