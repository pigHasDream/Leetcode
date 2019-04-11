#include <iostream>
#include <string>
#include <vector>
using namespace std;

/***************************************

char:  | a | b | a | b | a | b | c | a |
index: | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 
value: | 0 | 0 | 1 | 2 | 3 | 4 | 0 | 1 |

The length of the longest proper prefix 
in the (sub)pattern that matches a 
proper suffix in the same (sub)pattern.

A A A C A A A A
0 1 2 0 1 2 3 3

***************************************/

void computeLPS(string& pattern, vector<int>& lps) {
  // LPS: longest prefix also a surfix
  int len = 0;  // lenght of the previous longest prefix suffix
  lps[0] = 0; // lps[0] is always 0
  int i = 1;

  // the loop calculates lps[i] for i = 1 to M-1
  while (i < pattern.length()) {
    if (pattern[i] == pattern[len]) {
      ++len;
      lps[i] = len;
      ++i;
    } else {
      if (len != 0) {
        // This is tricky. Consider the example AAACAAAA and i = 7.
        len = lps[len - 1];

        // Also, note that we do not increment i here
      } else {
        lps[i] = 0;
        ++i;
      }
    }
  }
} 

int KMPSearch(string& pattern, string& str) {
    
    int patLength = pattern.length();
    int strLength = str.length();
    
    vector<int> lps(patLength);
    computeLPS(pattern, lps);
 
    
    int i = 0;   // str      pos
    int j = 0;  // pattern  pos
    
    while (i < strLength) {
        
        if (str[i] == pattern[j]) {
            ++i;
            ++j;
        } else {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if(j != 0)
               j = lps[j-1];
            else
               i += 1;
        }
        
        if (j == patLength) {
            return  i - j;
            //j = lps[j-1];
        }
    }
    
}
 
void printLPS(string& s, vector<int>& t) {
    cout << "PAT: ";
    
    for (int i = 0; i < s.length(); ++i)
        cout << s[i] << " ";
    cout << endl;
    
    cout << "LPS: ";
    for (int i = 0; i < t.size(); ++i)
        cout << t[i] << " ";
    cout << endl;
}
 
// Driver program to test above function
int main() {
    string str = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";
    
    
    vector<int> t(pat.length());
    computeLPS(pat, t);
    printLPS(pat, t);
    
    cout << endl <<  KMPSearch(pat, str);
    return 0;
}
