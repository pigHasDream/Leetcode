class Solution {
public:
  int reversePairs(vector<int>& nums) {
    vector<int> vec(nums);
    return mergeSort(nums, 0, nums.size()-1);
  }
  
  int mergeSort(vector<int>& vec, int start, int end) {
    if(start >= end) return 0;
    
    int mid = start + (end - start)/2;
    int count = mergeSort(vec, start, mid) + mergeSort(vec, mid+1, end);
    
    // count the two splits
    for(int i=start, j=mid+1; i<=mid and j<=end;) {
      if(long(vec[i]) > 2*long(vec[j])) {
        count += mid-i+1;
        ++j ;
      }
      else ++i;
    }
    
    // merging the sorting, or just call sort(vec.begin()+start, vec.begin()+end+1);
    vector<int> merge;
    for(int i=start, j=mid+1; i<=mid or j<=end;) {
      if(i<=mid and (j>end or vec[i] < vec[j])) 
        merge.emplace_back(vec[i++]);
      else 
        merge.emplace_back(vec[j++]);
    }
    
    for(int k=start; k<=end; ++k) vec[k] = merge[k-start];
    
    return count;
  }
  
};
