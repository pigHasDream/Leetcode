class Solution {
public:
    string rearrangeString(string s, int k) {
      if(k==0) return s;
      
      vector<int> hash(26,0);
      for(const auto& t : s)
        ++hash[t-'a'];

      priority_queue<pair<int, char>> que;

      for(int i=0; i<hash.size(); ++i)
        if(hash[i]>0) 
          que.emplace(hash[i], char('a'+i));

      string res;
      int len = s.size();
      while(que.size()) {
        vector<pair<int,char>> holder;
        
        // the 'bnd' is min(k, len) is the key!!
        // it'll keep the min of k or remaining len of string!
        int bnd = min(k, len);
        for(int i=0; i<bnd; ++i) {
          if(que.empty()) return "";
          
          auto top = que.top(); que.pop();
          res += top.second;
          if(top.first > 1) {
            holder.emplace_back(top.first-1, top.second);
          }
          --len;
        }

        for(const auto& p : holder)
          que.emplace(p);
      }

      return res;
  }
};
