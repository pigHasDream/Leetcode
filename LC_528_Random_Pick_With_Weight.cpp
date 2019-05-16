class Solution {
  vector<int> sum_;
public:
  Solution(vector<int>& w) {
    sum_ = w;
    for(int i=1; i<w.size(); ++i)
      sum_[i] += sum_[i-1];
  }

  int pickIndex() {
    int s = rand()%sum_.back();
    // we need to use upper_bound in case the returned iter is 0!
    return upper_bound(sum_.begin(), sum_.end(), s) - sum_.begin();
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
