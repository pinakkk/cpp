#include <iostream>
#include <vector>
using namespace std;

struct Edge {
  int u;
  int v;
  int wt;
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<Edge> edges;

  for (int i = 0; i < m; i++) {
    int u, v, wt;
    cin >> u >> v >> wt;
    edges.push_back({u, v, wt});
  }

  // Bellman Ford
  int src = 1;
  vector<int> dist(n + 1, 1e9);
  dist[src] = 0;

  // Relax V - 1 Edges
  for (int i = 0; i < n - 1; i++) {
    for (auto edge : edges) {
      int u = edge.u;
      int v = edge.v;
      int wt = edge.wt;
      if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
        dist[v] = dist[u] + wt;
      }
    }
  }

  // Detect negative cycles
  bool hasNegativeCycle = false;

  for (auto edge : edges) {
    int u = edge.u;
    int v = edge.v;
    int wt = edge.wt;
    if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
      hasNegativeCycle = true;
      break;
    }
  }

  for (auto it : dist) {
    cout << it << " ";
  }

  if (hasNegativeCycle) {
    cout << " Has Negative Cycle " << endl;
  }

  return 0;
}