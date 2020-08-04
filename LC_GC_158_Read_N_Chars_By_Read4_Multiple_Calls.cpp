class Solution {
  constexpr static int mod_ = 4;
  char buf_[mod_];
  int bufCnt_;
  int bufStart_;
  
public:
  /**
   * @param buf Destination buffer
   * @param n   Number of characters to read
   * @return    The number of actual characters read
   */
  Solution() {
    memset(buf_, '\0', mod_);
    bufCnt_ = 0;
    bufStart_ = 0;
  }
  
  int read(char *buf, int n) {
    
    int cnt = 0;
    while(cnt < n) {
      int rem = n - cnt;
      if(bufCnt_ > 0) {
        int sz = min(bufCnt_, rem);
        memcpy(buf+cnt, buf_+bufStart_, sz);
        cnt += sz;
        
        bufStart_ = (bufStart_ + sz) % mod_;
        bufCnt_ -= sz;
      }
      else {
        int ret = read4(buf_);
        int sz = min(ret, rem);
        memcpy(buf+cnt, buf_, sz);
        cnt += sz;
        bufStart_ = sz % mod_;  
        bufCnt_ = ret - sz;

        if(ret < mod_) 
          break;
      }
    }

    return cnt;
  }
};
