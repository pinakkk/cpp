#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  //  //  graph is being stored here, all elements initialized as 0
  //  // using matrix O(N * N) space
  //   vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

  //   for (int i = 0; i < m; i++) {
  //     int u, v;
  //     cin >> u >> v;
  //     adj[u][v] = 1;
  //     adj[v][u] = 1;
  //   }

  //   for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < n; j++) {
  //     cout << adj[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  // // using adjacency list O(2 * E);
  // // in case of directed : O(E)
  vector<int> adj[n + 1];

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    // Undirected
    adj[u].push_back(v);
    adj[v].push_back(u);

    // for directed
    // adj[u].push_back(v);
  }

  for (int i = 0; i < n; i++) {
    cout << i << " --> ";
    for (auto it : adj[i]) {
      cout << it << " ";
    }
    cout << endl;
  }

  return 0;
}