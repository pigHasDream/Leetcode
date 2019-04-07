
void monotoneStack(vector<int>& A) {

  // stack stores index
  stack<int> stc;
  stc.push(A[0]);

  for(int i=1; i<A.size(); ++i) {
    while(stc.size() and A[i] > A[stc.top()]) {
      auto top = stc.top();
      stc.pop();
      // do something
    }
    // do something;
    stc.emplace(A[i]);
  }

  return;
}

