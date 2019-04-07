
void doBFS() {

  queue<int> que;
  que.push(initVal);

  while(que.size()) {
    for(int i=que.size(); i>0; --i) {
      auto top = que.front(); 
      que.pop_front();

      // do something based on the 'top'.

      que.emplace_back(top.next);
    }
  }

}
