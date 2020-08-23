class Solution {
  struct UF {
    UF(int m) : parent_(m+1), visit_(m+1,0), count_(m+1,1), rank_(m+1,0), group_(m+1,0) {
      iota(parent_.begin(), parent_.end(), 0);
    }
    
    vector<int> parent_;
    vector<int> rank_;
    
    // check if a number has been visited!
    vector<int> visit_;
    // each group how many attached
    vector<int> count_;
    // <group size, count>
    vector<int> group_;

    void self(int n) {
      ++group_[1];
    }
    
    int find(int n) {
      if(parent_[n]!=n) {
        parent_[n] = find(parent_[n]);
      }
      return parent_[n];
    }

    void unin(int a, int b) {
      int pa = find(a);
      int pb = find(b);

      if(pa != pb) {
        --group_[count_[pa]];
        --group_[count_[pb]];
        count_[pa] = count_[pb] = count_[pa] + count_[pb];
        ++group_[count_[pa]];

        if(rank_[pa]<rank_[pb]) {
          parent_[pa] = pb;
        }
        else if(rank_[pa]>rank_[pb]) {
          parent_[pb] = pa;
        }
        else {
          parent_[pb] = pa;
          ++rank_[pa];
        }
      }
    }
  };
  
public:
  int findLatestStep(vector<int>& arr, int T) {
    UF uf(arr.size());
    
    int step = 1;
    int idx = 0;
    int maxNum = arr.size();
    int last = -1;
    
    while(step <= arr.size()) {
      
      int num = arr[idx++];
      int prev = num-1;
      int next = num+1;
      
      uf.visit_[num] = 1;
      uf.self(num);
      
      if(prev > 0 and uf.visit_[prev]) {
        uf.unin(prev, num);
      }
      if(next <= arr.size() and uf.visit_[next]) {
        uf.unin(next,num);
      }
      
      if(uf.group_[T] > 0)
        last = step;
      
      ++step;
    }
      
    return last;
  }
};
