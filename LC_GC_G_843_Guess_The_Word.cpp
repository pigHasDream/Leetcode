/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
  void findSecretWord(vector<string>& wordlist, Master& master) {
    
    auto isMatch = [&](const string& str1, const string& str2, const int mat) {
      int cnt = 0;
      for(int i=0; i<6; ++i) {
        if(str1[i] == str2[i]) ++cnt;
      }
      return mat == cnt;
    };

    for(int i=0; i<10; ++i) {
      
      string word = wordlist[rand()%wordlist.size()];
      int match = master.guess(word);
      if(match == 6) break;
      
      vector<string> temp;
      for(const auto& w : wordlist) {
        if(isMatch(w, word, match))
          temp.emplace_back(w);
      }
      
      swap(temp, wordlist);
    }
    
  }
};
