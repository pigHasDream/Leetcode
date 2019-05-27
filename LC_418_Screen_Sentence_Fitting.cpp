class Solution {
public:
  int wordsTyping(vector<string>& sentence, int rows, int cols) {
    // s is the formatted sentence to be put to our screen
    string s;
    for(const auto& word : sentence) s += word + " ";

    int count = 0;
    for (int r = 0; r < rows; ++r) {
      // full fill current collumn, so advance by cols
      count += cols;
      // if the ending is ' ', advance 1 more to skip the ' ' padding.
      // although it's already fitted into one row.
      if(s[count % s.length()] == ' ') ++count;
      // it cannot fit completely, we need to look back to the first space.
      else {
        while (count > 0 and s[count % s.length()] != ' ') --count;
        ++count; 
      }
    }

    return count / s.length();
  }
};
