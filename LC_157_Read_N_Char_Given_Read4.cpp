// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
      
      constexpr int BND = 4;
      int count = 0;
      int rd4Count = BND;
      char tmp[BND];
      
      while(true) {
        rd4Count = read4(tmp);
        if(rd4Count == 0) return count;
        int byte = min(rd4Count, n-count);
        memcpy(buf+count, tmp, byte);
        count += byte;
      }
      
      return count;
    }
};
