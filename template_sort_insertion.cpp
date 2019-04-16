for (auto i = v.begin(); i != v.end(); ++i) {
  std::rotate(std::upper_bound(v.begin(), i, *i), i, i+1);
}
 
