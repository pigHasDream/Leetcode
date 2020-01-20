class Foo {
  std::mutex mu_;
  std::condition_variable cond_;
  int count_;
  
public:
  Foo():count_(0) {
  }

  void first(function<void()> printFirst) {

    std::unique_lock<std::mutex> locker(mu_);
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    count_ = 1;
    cond_.notify_all();
    
  }

  void second(function<void()> printSecond) {
    
    std::unique_lock<std::mutex> locker(mu_);
    // printSecond() outputs "second". Do not change or remove this line.
    // cond_.wait to hold the locker(mutex) and will send out to unlock if it still need to sleep
    cond_.wait(locker, [this](){ return count_ == 1;});
    printSecond();
    count_ = 2;
    cond_.notify_all();
      
  }

  void third(function<void()> printThird) {

    std::unique_lock<std::mutex> locker(mu_);
    // printThird() outputs "third". Do not change or remove this line.
    // cond_.wait to hold the locker(mutex) and will send out to unlock if it still need to sleep
    cond_.wait(locker, [this](){ return count_ == 2;});
    
    printThird();
    
  }
};
