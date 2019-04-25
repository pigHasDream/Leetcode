class Solution {
  vector<vector<int>> memo_;
  
  int minDist(const string& s, const string& t, int i, int j) {
    if(s.size() == i) return t.size()-j;
    if(t.size() == j) return s.size()-i;
    
    if(memo_[i][j] != -1) return memo_[i][j];
    
    int res = 0;
    if(s[i]==t[j]) {
      res = minDist(s, t, i+1, j+1);
    }
    else {
      res = 1 + min(min(minDist(s, t, i+1, j),
                        minDist(s, t, i, j+1)),
                    minDist(s, t, i+1, j+1));
    }
    
    return memo_[i][j] = res;
    
  }
  
public:
  int minDistance(string word1, string word2) {
    
    int size1 = word1.size();
    int size2 = word2.size(); 
    
    memo_.resize(size1, vector<int>(size2, -1));
    
    return minDist(word1, word2, 0, 0);
    
  }
};
