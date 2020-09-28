//---------------------------------------------
// This is the solution doing char copying one by one!
class Solution {
  int buf4Start_ = 0;
  int buf4Count_ = 0; 
  char buf4_[4] = {0};
  
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
  int read(char *buf, int n) {
    
    int count = 0;
    int idx = 0;
    
    while(count < n) {
      if(buf4Count_ > 0) {
        buf[idx++] = buf4_[buf4Start_++];
        --buf4Count_;
        ++count;
      }
      else {
        buf4Count_ = read4(buf4_);
        if(buf4Count_ == 0) break;
        
        buf4Start_ = 0;
      }
    }

    return count;
  }
};


//---------------------------------------------

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


//---------------------------------------------
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
  // They are all serving the buf4
  int buf4Rem_ = 0; 
  char buf4_[4];
  int buf4Start_ = 0;
  
public:
  /**
   * @param buf Destination buffer
   * @param n   Number of characters to read
   * @return    The number of actual characters read
   */
  int read(char *buf, int n) {
    if(buf == nullptr) 
      return 0;
    
    // 1. Head case:
    //    buf4_ already holds some data
    //    a) the data len is smaller than n, need to call read4
    //    b) the data len is larger or equal to n, no need to call read4
    // 2. Middle case:
    //    buf4_ has no data
    //    need to call read4 and use the remaining n to compare with 4
    // 3. Tail case:
    //    buf4_ holds extra data or just clean, need to update buf4Ptr_
    
    int count = 0;

    // Take the center of whether buf4Rem and buf4Cnt of each return.
    
    if(buf4Rem_ > 0) {
      if(n >= buf4Rem_) {
        memcpy(buf+count, buf4_+buf4Start_, buf4Rem_);
        count += buf4Rem_;
        n -= buf4Rem_;
        buf4Rem_ = 0;
        buf4Start_ = 0;
      }
      else {
        memcpy(buf+count, buf4_+buf4Start_, n);
        buf4Rem_ -= n;
        buf4Start_ += n;
        count += n;
        return n;
      }
    }
    
    int buf4cnt = 0;
    // check 4, buf4cnt, n, relations!
    while(n>0 and (buf4cnt = read4(buf4_))) {
      // buf4 is full, now check n and the 4 relation
      if(buf4cnt == 4) {
        // this will continue the loop
        if(n>=4) {
          memcpy(buf+count, buf4_, 4);
          n -= 4;
          count += 4;
          buf4Rem_ = 0;
          buf4Start_ = 0;
        }
        else {
          // this will break
          memcpy(buf+count, buf4_, n);
          count += n;
          buf4Rem_ = 4-n;
          buf4Start_ = n;
          break;
        }
      }
      // buf 4 is not full, now check n and buf4cnt
      else {
        if(buf4cnt <= n) {
          memcpy(buf+count, buf4_, buf4cnt);
          count += buf4cnt;
          buf4Rem_ = 0;
          buf4Start_ = 0;
          break;
        }
        else {
          memcpy(buf+count, buf4_, buf4cnt);
          count += n;
          buf4Rem_ = buf4cnt - n;
          buf4Start_ = n;
          break;
        }
      }
    }

    return count;
  }
};
