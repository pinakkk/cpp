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

  int src = 1;
  vector<int> dist(n + 1, 1e9);
  dist[src] = 0;

  // Relax V - 1 edges
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

  // Negative Cycle detection;
  bool negativeCycle = false;

  for (auto edge : edges) {
    int u = edge.u;
    int v = edge.v;
    int wt = edge.wt;
    if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
      negativeCycle = true;
      break;
    }
  }

  cout << "Shortest Distances : " << endl;
  for (int i = 1; i <= n; i++) {
    cout << i << " --> " << dist[i] << endl;
  }

  if (negativeCycle) {
    cout << " Negative Cycle Exists " << endl;
  } else {
    cout << " Negative Cycle Does Not Exist " << endl;
  }

  return 0;
}