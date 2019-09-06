class Solution {
public:
  vector<string> addOperators(string num, int target) {
    
    int len = num.size();
    vector<string> res;
    
    function<void(int,long,string,long)> doDFS = 
      [&] (int idx, long curSum, string curSol, long prevNum) {
      
      if(idx >= len) {
        if(curSum == target) 
          res.emplace_back(curSol);
        
        return;
      }
      
      // This for-loop is the key to simplify the whole thing
      // it takes care the of no-opt case by gradually expanding the length!
      for(int l=1; l<=len-idx; ++l) {
        string seg = num.substr(idx, l);
        if(seg.size()>1 and seg.front() == '0') break;
        long newNum = stol(seg);
        
        if(idx==0) {
          doDFS(idx+l, newNum, seg, newNum);
          continue;
        }
        
        doDFS(idx+l, curSum + newNum, curSol+"+"+seg, newNum);
        doDFS(idx+l, curSum - newNum, curSol+"-"+seg, -newNum);
        // below always treat the entire product as a number.
        doDFS(idx+l, 
              curSum - prevNum + prevNum*newNum, 
              curSol+"*"+seg,
              prevNum*newNum);
      }
      
    };

    doDFS(0,0,"",0);
    
    return res;
    
  }
};
