class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> res;
    unordered_map<int,int> freq;
    
    int maxFreq = 1;
    for(const auto& n : nums) {
      maxFreq = max(maxFreq, ++freq[n]);
    }
    
    unordered_map<int, vector<int>> bucket;
    
    for(const auto& p : freq) {
      bucket[p.second].emplace_back(p.first);
    }
    
    for(int i=maxFreq; i>0; --i) {
      res.insert(res.end(), bucket[i].begin(), bucket[i].end());
      if(res.size() >= k) 
        break;
    }

    return res;
  }
  
};
