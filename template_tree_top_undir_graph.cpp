// This converts a binary tree to a undirected graph
// Source node in the graph has value of sourceVal.

class ConvertTreeToGraph {

  unordered_map<TreeNode*, vector<TreeNode*>> graph;
  TreeNode* sourceNode_;

public:
  void topLevel (TreeNode* root, int sourceVal) {
    buildGraph(root, sourceVal, nullptr);
  }

  void buildGraph(TreeNode* curNode, 
                  int sourceVal, 
                  TreeNode* pNode) {
    
    if(curNode == nullptr) return;
    
    // set the source node
    if(curNode->val == sourceVal) 
      sourceNode_ = curNode;
    
    // connect the current node and parent node
    // unidrectional so both edges
    if(pNode != nullptr) {
      graph_[pNode].emplace_back(curNode);
      graph_[curNode].emplace_back(pNode);
    }
    
    // recursively build left and right child
    buildGraph(curNode->left, k, curNode);
    buildGraph(curNode->right, k, curNode);
  }

};
