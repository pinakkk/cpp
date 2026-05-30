#include <iostream>
#include <vector>
using namespace std;

// bool dfs(int node, vector<int> adj[], vector<int> &vis, int count, int n) {
//   if (count == n) {
//     return true;
//   }

//   vis[node] = 1;

//   for (auto next : adj[node]) {
//     if (!vis[next]) {
//       if (dfs(next, adj, vis, count + 1, n)) {
//         return true;
//       }
//     }
//   }
//   vis[node] = 0;
//   return false;
// }

// Hamiltonian circle

bool dfs(int node, int start, vector<int> adj[], vector<int> &vis, int count,
         int n) {

  vis[node] = 1;

  if (count == n) {
    for (auto next : adj[node]) {
      if (next == start)
        return true;
    }
    vis[node] = 0;
    return false;
  }

  for (auto next : adj[node]) {
    if (!vis[next]) {
      if (dfs(next, start, adj, vis, count + 1, n))
        return true;
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

    if (dfs(i, i, adj, vis, 1, n)) {
      found = true;
      break;
    }
  }

  if (found)
    cout << "Hamiltonian Circuit Exists";
  else
    cout << "Hamiltonian Circuit Does Not Exist";

  return 0;
}