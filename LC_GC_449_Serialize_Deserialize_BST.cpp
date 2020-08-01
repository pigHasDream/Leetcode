class Codec {
public:

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string data;
    
    function<void(TreeNode*)> doPreOrder = [&](TreeNode* rt) {
      if(rt==nullptr) return;
      
      char buf[sizeof(int)];
      memcpy(buf, &(rt->val), sizeof(int));
      for(const auto& c : buf)
        data += c;
      
      doPreOrder(rt->left);
      doPreOrder(rt->right);
    };
    
    doPreOrder(root);

    return data;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    
    int pos = 0;
    
    function<TreeNode*(int,int)> doRecursion = [&](int minVal, int maxVal) -> TreeNode* {
      if(pos >= data.size()) 
        return nullptr;
      
      char buf[sizeof(int)];
      for(int i=0; i<sizeof(int); ++i)
        buf[i] = data[pos+i];
        
      int val;
      memcpy(&val, buf, sizeof(int));
      if(val < minVal or val > maxVal)
        return nullptr;
      
      pos += sizeof(val);
      
      TreeNode* rt = new TreeNode(val);
      rt->left = doRecursion(minVal, val);
      rt->right = doRecursion(val, maxVal);
      
      return rt;
    };

    return doRecursion(INT_MIN, INT_MAX);
  }
  
};
