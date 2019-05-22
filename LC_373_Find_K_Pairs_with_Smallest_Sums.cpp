class Solution {
public:
	// view the problem as a dijkstra
  // essentially we have a 2-D matrix starting from top left to right bottom.
  // Each time we expand by one element.
  // But the trick here is:
  //
  // Since each row and column is sorted, so long as we plant the next row's
  // first element and it's not yet popped out, we can safely expand the frontier
  // just row-by-row!
  //
  //
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    
    int n1 = nums1.size(), n2 = nums2.size();
    if(n1==0 or n2==0) return {};
    
    // tuple: 0: sum, 1: first elem, 2: second elem
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> heap; 
    heap.emplace(nums1[0]+nums2[0], 0, 0);
    
    vector<vector<int>> res;
    while(k-- >0 and heap.size()) {
      auto top = heap.top();
      heap.pop();
      
      int idx1 = get<1>(top);
      int idx2 = get<2>(top);
      res.emplace_back(vector<int>({nums1[idx1], nums2[idx2]}));
      
      if(idx1<n1-1) 
        heap.emplace(nums1[idx1+1]+nums2[idx2], idx1+1, idx2);
      if(idx1 == 0 and idx2 < n2-1)
        heap.emplace(nums1[idx1]+nums2[idx2+1], idx1, idx2+1);
    }

    return res;
  }
};
