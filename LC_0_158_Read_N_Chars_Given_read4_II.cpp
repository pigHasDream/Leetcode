// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
  char buf4[4];
  // i4_ current idx to be read in buf4
  // n4_ the total valid size of buf4 after read4
  int i4_ = 0;
  int n4_ = 0;
  
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
      int idx = 0;
      // so long as idx still smaller than n, we continue
      while(idx < n) {
        // buf4 still has elem to copy first
        if(i4_<n4_) {
           buf[idx++] = buf4[i4_++];
        }
        // now needs to copy from the read4
        else {
          // enough to copy over, so we can directly copy read4 to buf
          // skipping the buf4 for duplicated copying 
          if(n-idx >=4) {
            int len = read4(buf+idx);
            idx += len;
            if(len<4) return idx;
          }
          // not enough to copy over, so there is a deemed left over so
          // need to keep the residue in buf4
          else {
            n4_ = read4(buf4);
            i4_ = 0; 
            if(n4_ == 0) return idx;
          }
        }
      }
      
      return idx;
    }
};
