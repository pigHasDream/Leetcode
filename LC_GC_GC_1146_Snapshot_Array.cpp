class SnapshotArray {
  vector<map<int,int>> data_;
  int count_;
  
public:
  SnapshotArray(int length) :
  data_(length),
  count_(0) {
    for(auto& mp : data_)
      mp.emplace(-1, 0);
  }

  // lazy update
  void set(int index, int val) {
    data_[index][count_] = val;
  }

  int snap() {
    return count_++;
  }

  int get(int index, int snap_id) {
    
    const auto& snap2hist = data_[index];
    
    // This is the way to get the smaller or equal to snap_id
    return prev(snap2hist.upper_bound(snap_id))->second;
    
  }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
