/* 
unlike tree deep copy, graph deep copy involves 
same node can be visited multiple times due to 
different types of edges during the traversal.

Therefore, we need to use a visit marker

For tree deep copy, each tree node is visited
exactly once, so no need to check the visit

*/

class Solution {
public:
  Node* cloneGraph(Node* node) {
    // Need to check uniqueness, as a node
    // may be linked by multiple neighbors
    unordered_map<Node*, Node*> old2new;
    
    // Time O(V+E), Space O(V)
    function<Node*(Node*)> doDFS =
      [&](Node* node) -> Node* {
      
      if(node == nullptr) 
        return nullptr;
    
      // if already created return
      if(old2new.count(node)) 
        return old2new[node];

      old2new[node] = new Node(node->val); 

      for(const auto& nxt : node->neighbors) {
        old2new[node]->neighbors.
          emplace_back(doDFS(nxt));
      }
      
      return old2new[node];
    };
    
    return doDFS(node);
  }
};
