/*********************************************************************************
Segment tree is a balanced binary tree with O(logn) height given n input segments.
Segment tree supports fast range query O(logn + k), and update O(logn).
Building such a tree takes O(nlog(n)) time and space.

All leaf nodes stores the original num array.
Tree is built up upon the range index, recursively.
Each parent node caches operations of children values, can be sum, max, min etc.
**********************************************************************************/

// =========================================================
class segTreeNode {
  public:
    segTreeNode(int start, int end, int value, 
                segTreeNode* left = nullptr, 
                segTreeNode* right = nullptr)
              : start_(start),
                end_(end),
                value_(value),
                left_(left),
                right_(right) { }

    ~segTreeNode() {
      delete left_;
      delete right_;
      left_ == nullptr;
      right_ == nullptr;
    }

    int start_;
    int end_;
    int value_;
    segTreeNode* left_;
    segTreeNode* right_;

 private:
    segTreeNode(const segTreeNode& tree) = delete;
    segTreeNode& operator=(const segTreeNode& tree) = delete;
};


// =========================================================
class segTreeUtil {
  public:
    // -----------------------------------------------------
    segTreeNode* doBuildTree(int start, int end, const vector<int>& nums) {

      // build segment tree with range
      if(start == end) {
        // leaf node
        return new segTreeNode(start, end, nums[start], nullptr, nullptr);
      }

      int mid = start + (end-start)/2;
      auto left = doBuildTree(start, mid, nums);
      auto right = doBuildTree(mid+1, end, nums);

      // current parent node, considering the left/right children
      return new segTreeNode(start, end, doCalc(left->value, right->value), left, right);
    }

    // -----------------------------------------------------
    void doUpdateTree(segTreeNode* root, int index, int newValue) {

      // leaf node update
      if(root->start == index and root->end == index) {
        root->value = newValue;
        return;
      }

      int mid = root->start + (root->end - root->start)/2;
      if(index <= mid) {
        doUpdateTree(root->left, index, newValue);
      }
      else {
        doUpdateTree(root->right, index, newValue);
      }

      // parent node needs to be updated!
      root->value = doCalc(root->left->value, root->right->value);
    }

    // -----------------------------------------------------
    int getRangeValue(segTreeNode* root, int i, int j) {

      if(i == root->start and j == root->end)
        return root->value;

      int mid = root->start + (root->end - root->start)/2;

      // This is crucial! We have 3 cases:
      if(j<mid) {
        return getRangeValue(root->left, i, j);
      }
      else if (i>mid) {
        return getRangeValue(root->right, i, j);
      }
      else {
        auto lValue = getRangeValue(root->left, i, mid);
        auto rValue = getRangeValue(root->right, mid+1, j);

        return doCalc(lValue, rValue);
      }
    }

  private:
    // -----------------------------------------------------
    inline int doCalc(int lValue, int rValue) {
      // This can be configured per situations
      return lValue + rValue;
      // return max(lValue, rValue);
      // return min(lValue, rValue);
    }

};
