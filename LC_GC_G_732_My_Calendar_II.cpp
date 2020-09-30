class MyCalendarThree {
  map<int,int> event_;
public:
  MyCalendarThree() {

  }

  int book(int start, int end) {
    ++event_[start];
    --event_[end];
    
    int count = 0;
    int maxCount = 0;
    for(const auto& p : event_) {
      // here is the key!
      count += p.second; 
      maxCount = max(maxCount, count);
    }

    return maxCount;
  }
};
