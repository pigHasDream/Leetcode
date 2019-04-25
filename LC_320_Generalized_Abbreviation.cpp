class Solution {
public:
  vector<string> generateAbbreviations(string word) {
    
    vector<string> res;
    string curSol = "";
    doDFS(word, res, curSol, 0, 0);
    
    return res;
  }
  
  void doDFS(string word, vector<string>& res, string curSol, int index, int numCount) {
    
    if(index == word.size()) {
      if(numCount>0)  curSol += to_string(numCount);
      res.emplace_back(curSol);
      return;
    }
    
    // case 1: do abbreviation
    // curSol do not change anything, we'll defer it to
    // either the termination process or when we decides to not
    // abbreviate the letter!!
    
    doDFS(word, res, curSol, index+1, numCount+1);
    
    // case 2: do not do abbreviation
    // now, we process the numCount and merge it to the curSol.
    // also, clear the numCount!
    
    if(numCount > 0) curSol += to_string(numCount);
    
    curSol += word[index];
    doDFS(word, res, curSol, index+1, 0);
    
  }
};
