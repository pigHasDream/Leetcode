class Solution {
public:
  int wordsTyping(vector<string>& sentence, int rows, int cols) {
    // s is the formatted sentence to be put to our screen
    string s;                                          
    for(const auto& word : sentence) s += " " + word; 

    // skip the very first space char ' '
    int start = 1;                                          
    // advance start by one so s[start & s.length()] != ' '
    for (int r = 0; r < rows; ++r, ++start) {               
      // full fill current collumn, so start advance by cols
      start += cols;                                      
      // make sure s[start & s.length()] == ' '
      while (s[start % s.length()] != ' ') --start;    
    }

    // we began with start == 1, so (start-1) is the valid length
    return (start-1) / s.length();                            
  }
};
