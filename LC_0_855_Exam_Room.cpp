class ExamRoom {
  
  set<int> room_;
  int seatSize_;
  
public:
  ExamRoom(int N) {
    seatSize_ = N;
  }

  int seat() {
    if(room_.empty()) {
      room_.emplace(0);
      return 0;
    }
    
    if(room_.size() == 1) {
      int idx = *room_.begin();
      if(idx>=seatSize_/2) {
        idx = 0;
      }
      else idx = seatSize_-1;
      room_.emplace(idx);
      return idx;
    }
    
    int left = 0, maxLen = *room_.begin();
    int pos = 0;
    for(int i : room_) {
      if(i==left) continue;
      // NOTE!! maxLen must be defined as
      // whatif we insert, then the maxLen!!
      // Because, otherwise, there may be unbalanced
      // [2,3] distance, in right side, but [2,2] case
      // in left side, they are not the same before whatif.
      // But, they are literally the same after whatif.
      // And because of that, we should do the [2,2] because
      // it's smaller in index!
      if(maxLen < (i-left)/2) {
        pos = left+(i-left)/2;
        maxLen = (i-left)/2;
      }
      left=i;
    }
    
    if(seatSize_-1-left > maxLen) {
      pos = seatSize_-1;
    }
    room_.emplace(pos);
    
    return pos;
  }

  void leave(int p) {
    room_.erase(p);
  }
};
