/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
  unordered_map<Node*, Node*> map_;
  
  // Need to take care the loop case!
  // So keep a map for the mapping nodes,
  // when re-visit the same node, directly
  // return it. Otherwise, the neighbor nodes
  // will be recursively created.
public:
  Node* cloneGraph(Node* node) {
    if(node == nullptr) return nullptr;
    if(map_.count(node)) return map_[node];
    
    Node* newNode = new Node(node->val, vector<Node*>());
    
    map_[node] = newNode;
    
    for(auto next : node->neighbors) {
      newNode->neighbors.emplace_back(cloneGraph(next));
    }

    return newNode;
  }
};
