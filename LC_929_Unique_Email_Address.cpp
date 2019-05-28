class Solution {
public:
  int numUniqueEmails(vector<string>& emails) {
    
    unordered_set<string> hash;
    for(const auto& em : emails) {
      // string.find returns size_t position
      auto p = em.find('@');
      auto global = em.substr(p+1);
      
      // substr returns a new string
      string local = em.substr(0,p);
      // below is a famous erase/remove idiom!!
      // This is due to the remove is not actually remove, but a 
      // shift! So erase needs to clean up the tailing ones
      // This is the case for vector, string etc, but not set/map
      // string.erase(remove(string.begin(), string.end(), val), string.end);
      local.erase(remove(local.begin(), local.end(), '.'), local.end());
      
      auto plus = local.find('+');
      local = local.substr(0, plus);
      
      // construct the full string
      hash.insert(local+'@'+global);
    }
    
    return hash.size();
  }
};
