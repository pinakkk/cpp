#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool isSafe(int node, int col, vector<int> adj[], vector<int> &color) {
  for (auto it : adj[node]) {
    if (color[it] == col) {
      return false;
    }
  }
  return true;
}

bool solve(int node, int n, int m, vector<int> adj[], vector<int> &color) {
  if (node > n) {
    return true;
  }

  for (int col = 1; col <= m; col++) {
    if (isSafe(node, col, adj, color)) {
      color[node] = col;

      if (solve(node + 1, n, m, adj, color)) {
        return true;
      }

      color[node] = 0;
    }
  }

  return false;
}
int main() {
  int n, e, m;
  cin >> n >> e >> m;

  vector<int> adj[n + 1];

  for (int i = 0; i < e; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> color(n + 1, 0);

  if (solve(1, n, m, adj, color)) {
    cout << "M Color Possible";
  } else {
    cout << "M Color Not Possible";
  }

  return 0;
}