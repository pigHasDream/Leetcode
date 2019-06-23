class Solution {
public:
  vector<string> expand(string S) {
    vector<string> res;
    
    vector<vector<string>> cands;
    vector<string> tmpCand;
    string tmpCur;
    
    for(int i=0; i<S.size(); ++i) {
      if(isalpha(S[i])) {
        tmpCur += S[i];
      }
      
      if(not isalpha(S[i]) or i==S.size()-1) {
        if(tmpCur.size()) {
          tmpCand.emplace_back(tmpCur);
          tmpCur.clear(); 
        }
        if((S[i] == '}' or S[i] == '{' or i==S.size()-1) and tmpCand.size()) {
          cands.emplace_back(tmpCand);
          tmpCand.clear();
        }
      }
    }
    
    function<void(int,string,int)> doDFS = [&](int candIdx, string curSol, int partCount) {
      if(partCount == cands.size()) {
        res.emplace_back(curSol);
        return;
      }
      
      for(int i=candIdx; i<cands.size(); ++i) {
        for(int j=0; j<cands[i].size(); ++j) {
          curSol += cands[i][j];
          doDFS(i+1, curSol, partCount+1);
          curSol.pop_back();
        }
      }
    };
    
    doDFS(0, "", 0);
    sort(res.begin(), res.end());

    return res;
  }
};
