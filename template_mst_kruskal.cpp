
// return mst's edge sum
int doKruskalMST() { 

  // edge cost first, then two nodes
	// {cost, {u, v}}
	vector<pair<int, pair<int, int>>> edges;
  int res = 0;
  
  // sort ascending based on first in pair
  sort(edges.begin(), edges.end()); 
  
  // union find to check circle
  UnionFind theUF(n);
  
  for (const auto& edge : edges) { 
    auto u = edge.second.first;
    auto v = edge.second.second;

    int pU = theUF.Find(u);
    int pV = theUF.Find(v);

    // if no circle, add new edge
    // i.e. two nodes to union.
    if (pU != pV) { 
      res += edge.first;
      theUF.union(u, v); 
    } 
  } 
  
  return res;

} 

