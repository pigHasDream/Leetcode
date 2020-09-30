class MyCalendar {
  vector<pair<int,int>> event_;
    
public:
  MyCalendar() {
  }

  bool book(int start, int end) {
    
    for(const auto& p : event_) {
      // Here is the key relation!
      if(max(start, p.first) < min(end, p.second))
        return false;
    }
    event_.emplace_back(start, end);

    return true;
  }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
