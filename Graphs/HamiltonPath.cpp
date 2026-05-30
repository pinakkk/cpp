#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<int> &vis, int count, int n) {
  if (count == n) {
    return true;
  }

  vis[node] = 1;

  for (auto next : adj[node]) {
    if (!vis[next]) {
      if (dfs(next, adj, vis, count + 1, n)) {
        return true;
      }
    }
  }
  vis[node] = 0;
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> adj[n];

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  bool found = false;

  for (int i = 0; i < n; i++) {
    vector<int> vis(n, 0);
    if (dfs(i, adj, vis, 1, n)) {
      found = true;
      break;
    }
  }

  if (found) {
    cout << "Hamiltonian Exists";
  } else {
    cout << "Does Not Exists";
  }

  return 0;
}