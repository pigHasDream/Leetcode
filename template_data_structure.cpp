// -----------------------------------------------------
// graph: {curNode, {outNode, edge_weight}
unordered_map<int, vector<pair<int,int>>> graph_;

// -----------------------------------------------------
// graph: if all nodes are int index, use vector
vector<int, vector<pair<int,int>>> graph_;

// -----------------------------------------------------
// graph: MST, {edgeCost, {startNode, endNode}}
vector<pair<int, pair<int, int>>> edges;

// -----------------------------------------------------
// bucket sort: {frequencyBucket, {elements}}
unordered_map<int, vector<int>> bucket_;

// -----------------------------------------------------
// tree node
struct TreeNode {
  int value_;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int val)
  : value_(val), left(nullptr), right(nullptr) {}
};

// -----------------------------------------------------
// list node
struct ListNode {
  int value_;
  ListNode* next;
  ListNode(int val): value_(val), next(nullptr) {}
};

// -----------------------------------------------------
// segment tree node
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

// -----------------------------------------------------

