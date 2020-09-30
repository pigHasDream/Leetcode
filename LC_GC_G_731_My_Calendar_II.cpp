class MyCalendarTwo {
  map<int, int> event_;
  
public:
  MyCalendarTwo() {
  }

  bool book(int start, int end) {
    // Here we record the event by sweeping the line
    ++event_[start];
    --event_[end];
    
    int count = 0;
    for(const auto& p : event_) {
      count += p.second;
      // Anytime we see > 2, it means the overlap is too high
      if(count > 2) {
        // here we need to undo the work
        --event_[start];
        ++event_[end];
				if(event_[start]==0) event_.erase(start);
        if(event_[end]==0) event_.erase(end);
        return false;
      }
    }

    return true;
  }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
