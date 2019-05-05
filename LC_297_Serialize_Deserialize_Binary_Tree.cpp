/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if(root == nullptr) return "# ";

    return to_string(root->val) + " " + 
           serialize(root->left) + 
           serialize(root->right);
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    stringstream ss(data);
    return des(ss);
  }
  
  TreeNode* des(stringstream& ss) {
    string cur;
    ss >> cur;
    
    if(cur == "#") return nullptr;
    auto root = new TreeNode(stoi(cur));
    
    root->left = des(ss);
    root->right = des(ss);
    
    return root;
  }
  
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
