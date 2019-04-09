
void doBFS() {

  queue<Node> que;
  que.push(init_Node);

  while(que.size()) {
    for(int i=que.size(); i>0; --i) {
      auto top = que.front(); 
      que.pop_front();

      // do something based on the 'top'.

      for(const auto& out : top.outNodes){
        // may skip visited nodes (with loop)
        // or update values for visited (no loop)
        que.emplace_back(top.next);
      }
    }
  }

}


