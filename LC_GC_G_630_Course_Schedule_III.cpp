class Solution {
public:
  int scheduleCourse(vector<vector<int>>& courses) {
    // This is still greedy!
    // Key is that, unlike other FIXED timing interval problems,
    // This one, only the length is fixed, while the starting time
    // can vary. But, the greedy holds on: at a given deadline, we
    // need to pick the shortest courses as long as all the deadlines
    // are before current deadline. Once a conflict arises, we kick out
    // the longest course!
    
    priority_queue<int, vector<int>, less<int>> que;
    sort(courses.begin(), courses.end(), [](const auto& a, const auto& b) {
      if(a.back() == b.back()) 
        return a.front() < b.front();
      return a.back() < b.back();
    });

    int totalLen = 0;
    for(const auto& course : courses) {
      que.emplace(course.front());
      totalLen += course.front();
      
      if(totalLen > course.back()) {
        totalLen -= que.top();
        que.pop();
      }
    }
    
    return que.size();
  }
};




/*

-------200--------------1250---1300--------------------3200
   <---]   
          <--------------]
                      <----------]
                    <----------------------------------]


*/
