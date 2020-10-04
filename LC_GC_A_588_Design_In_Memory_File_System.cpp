class FileSystem {
  struct Node {
    bool isFile_ = false; 
    string content_;
    map<string, Node*> kids_; 
    Node(bool isFile): isFile_(isFile) {};
    Node() : isFile_(false) {};
    ~Node() {
      for(auto& nxt : kids_)
        delete nxt.second;
    }
  };
  vector<string> parser(string path) {
    replace_if(path.begin(), path.end(), 
               [](auto& c){return c=='/';}, ' ');
    stringstream ss(path);
    string tmp;
    vector<string> res;
    while(ss >> tmp) {
      res.emplace_back(tmp);
    }
    return res;
  }
  Node root_;
public:
  FileSystem(): root_() {}

  vector<string> ls(string path) {
    vector<string> pathVec = parser(path);
    Node* ptr = &root_;
    for(const auto& nxt : pathVec) ptr = ptr->kids_[nxt];
    
    if(ptr->isFile_) return {pathVec.back()};
    
    vector<string> res;
    for(const auto& nxt : ptr->kids_)
      res.emplace_back(nxt.first);
      
    return res;
  }
  void mkdir(string path) {
    vector<string> pathVec = parser(path);
    Node* ptr = &root_;
    for(auto& nxt : pathVec) {
      if(ptr->kids_.count(nxt) == 0) {
        ptr->kids_[nxt] = new Node(false);
      }
      ptr = ptr->kids_[nxt];
    }
  }
  void addContentToFile(string filePath, string content) {
    vector<string> pathVec = parser(filePath);
    Node* ptr = &root_;
    for(auto& nxt : pathVec) {
      if(ptr->kids_.count(nxt) == 0)
        ptr->kids_[nxt] = new Node(true);
      
      ptr = ptr->kids_[nxt];
    }
    ptr->isFile_ = true;
    ptr->content_ += content;
  }
  string readContentFromFile(string filePath) {
    vector<string> pathVec = parser(filePath);
    Node* ptr = &root_;
    for(auto& nxt : pathVec) ptr = ptr->kids_[nxt];
    
    ptr->isFile_ = true;
    return ptr->content_;
  }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */


/*

/dir1/dir2/file5

[dir1, dir2, file5]

file1
file2
dir1/
  |-> file3
      file4
      dir2/
        |-> file5
            file6
            dir3/



*/
