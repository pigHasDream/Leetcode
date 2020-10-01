// =================================================================
// 4ms
class Solution {
public:
  bool makesquare(vector<int>& nums) {
    if(nums.size() < 4) return false;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum%4) return false;
    int side = sum/4;
    sort(nums.begin(), nums.end(), greater<int>());
    if(nums.front() > side) return false;
    
    vector<int> visit(nums.size(),0);
    
    // args: idx, groupIdx, count, curLen
    function<bool(int,int,int)> doDFS =
      [&](int idx, int groupIdx, int curLen) {
      if(curLen > side) return false;
      if(curLen == side) {
        if(groupIdx == 3)
          return true;
        
        // Here we start from scratch! Use a separate branch!
        // If we merge this into below for-loop (which is ok),
        // Then the for loop must start from 0 always, and relies on
        // visit[i] to skip duplications! It is quite slow!
        //
        // Becuase below loop is designed for SAME LEVEL groupIdx iteration,
        // we therefore can start the idx's next value onwards, to save TAT!
        // But we will branch out once a new group is formed!!
        return doDFS(0, groupIdx+1, 0);
      }
      if(idx == nums.size()) return false;
      
      for(int i=idx; i<nums.size(); ++i) {
        if(visit[i]) continue;
        // Here is the key that we skip the same element again!
        // as long as it's in the same iteration!
        // if the previous iteration is not using this element visit[i-1]==0!
        if(i>0 and nums[i] == nums[i-1] and visit[i-1]==0)
          continue;
        
        visit[i] = 1;
        if(doDFS(i+1, groupIdx, curLen+nums[i]))
          return true;
        visit[i] = 0;
      }
      
      return false;
    };

    return doDFS(0, 0, 0);
  }
};

// =================================================================
// 1300ms
// Below is a slower version which merges the groupIdx into a general for-loop case
// It is quite slow!
class Solution {
public:
  bool makesquare(vector<int>& nums) {
    if(nums.size() < 4) return false;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum%4) return false;
    int side = sum/4;
    sort(nums.begin(), nums.end(), greater<int>());
    if(nums.front() > side) return false;
    
    vector<int> visit(nums.size(),0);
    
    // args: idx, groupIdx, count, curLen
    function<bool(int,int,int)> doDFS =
      [&](int idx, int groupIdx, int curLen) {
      if(curLen > side) return false;
      if(curLen == side) {
        if(groupIdx == 3)
          return true;

        // NOTE below we just update the groupIdx and curLen
        // But it re-uses the same for-loop.
        // Therefore, we have to always start from 0 for-loop
        // It is very slow!
        
        ++groupIdx;
        curLen = 0;
      }

      if(idx == nums.size()) return false;
      
      // Here we have to always start from 0 because when new group is formed
      // we'll start from 0 again excluding all visited elements
      // But for most cases, this is rather slow!
      for(int i=0; i<nums.size(); ++i) {
        if(visit[i]) continue;
        // Here is the key that we skip the same element again!
        // as long as it's in the same iteration!
        // if the previous iteration is not using this element visit[i-1]==0!
        if(i>0 and nums[i] == nums[i-1] and visit[i-1]==0)
          continue;
        
        visit[i] = 1;
        // Note below the i starts from 0 again for all cases!
        if(doDFS(i, groupIdx, curLen+nums[i]))
          return true;
        visit[i] = 0;
      }
      
      return false;
    };

    return doDFS(0, 0, 0);
  }
};
