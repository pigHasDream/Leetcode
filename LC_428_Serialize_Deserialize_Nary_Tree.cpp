/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
public:

  // Encodes a tree to a single string.
  string serialize(Node* root) {
    // The solution is essentially a pre-order traversal!

    if(root == nullptr) return "# ";
    
    // Need to put children counts to the next value
    // of the root value.
    string res = to_string(root->val) + " " + to_string(root->children.size()) + " ";
    
    for(const auto& next : root->children)
      res += serialize(next);
    
    return res;
  }

  // Decodes your encoded data to tree.
  Node* deserialize(string data) {
    stringstream ss(data);
    return des(ss);
  }
  
  
  Node* des(stringstream& ss) {
    string cur;
    ss >> cur;
    if(cur == "#") return nullptr;
    
    // get the children value.
    int size = -1;
    ss >> size;
    
    vector<Node*> kids(size, nullptr);
    auto root = new Node(stoi(cur), kids);
    
    for(int i=0; i<size; ++i) {
      root->children[i] = des(ss);
    }
    
    return root;
  }
  
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
