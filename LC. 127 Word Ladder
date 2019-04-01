class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    unordered_set<string> set1;
    unordered_set<string> set2;
    
    if(not dict.count(endWord))
      return 0;
    
    set1.insert(beginWord);
    set2.insert(endWord);
    
    int level = 0;
    while(set1.size() and set2.size()) {
      
      // always assume set1 has smaller size
      if(set1.size() > set2.size())
        swap(set1, set2);
      
      ++level;
      unordered_set<string> setTmp;
      
      for(string s1 : set1) {
        int sz = s1.size();
        for(int i=0; i<sz; ++i) {
          string sTmp = s1;
          for(int j='a'; j<= 'z'; ++j) {
            sTmp[i] = j;
            
            if(set2.count(sTmp))
              return level + 1;
            
            if(not dict.count(sTmp))
              continue;
            
            dict.erase(sTmp);
            setTmp.insert(sTmp);
          }
        }
      }
      
      swap(setTmp, set1);
    }
    
    return 0;
  }
};
