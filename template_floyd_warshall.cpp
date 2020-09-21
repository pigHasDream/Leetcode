
// get shortest weighted paths from all node pairs in directed graph.
// This problem returns the longest path from node K. Nodes are marked as 0..N-1
// Since it's all inter-nodes, we need a adjacency matrix for easier way to proceed.
//
// To detect negtive cycle in the graph, we can also call a second time 
// DP loop, if any path gets improved, that is on a negative cycle.

class Solution {
  public:
  int networkDelayTime(vector<vector<int>>& weights, int N, int K) {
    constexpr int inf = 1e8;
    vector<vector<int>> cost(N, vector<int>(N, inf));

    for(const auto& w : weights) {
      // [u, v, weight]
      cost[w[0]-1][w[1]-1] = w[2];
    }

    for(int i=0; i<N; ++i)
      cost[i][i] = 0;

    for(int c=0; c<N; ++c) { // intermediate node
      for(int i=0; i<N; ++i) { // starting node
        for(int j=0; j<N; ++j) { // end node
          cost[i][j] = min(cost[i][j], cost[i][c] + cost[c][j]);
        }
      }
    }

    int res = *max_element(cost[K-1].begin(), cost[K-1].end());    

    return res == inf ? -1 : res;
  }

};
