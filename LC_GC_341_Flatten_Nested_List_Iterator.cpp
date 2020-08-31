class NestedIterator {
  using Iter = vector<NestedInteger>::iterator;
  using Vec = vector<NestedInteger>;

  // cpp iterator needs to work with the container!
  // holds iterator pointer and the container ref.
  stack<pair<Iter,Vec&>> stc_;
  int val_;
  
public:
  NestedIterator(vector<NestedInteger> &nestedList) :
    val_(0) 
    {
      if(nestedList.size())
        stc_.emplace(nestedList.begin(), nestedList);
    }

  int next() {
    return val_;
  }

  bool hasNext() {
    
    while(stc_.size()) {
      auto& [iter, vec] = stc_.top();
      
      if(iter->isInteger()) {
        val_ = iter->getInteger();
        
        if (++iter == vec.end()) 
          stc_.pop();
        
        return true;   
      }
      else {
        auto& newVec = iter->getList();
        
        if (++iter == vec.end()) 
          stc_.pop();
        
        if(newVec.size())
          stc_.emplace(newVec.begin(), newVec);
      }
    }
    
    return false;
  }
};
