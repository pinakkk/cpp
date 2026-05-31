#include <cstddef>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool isBipartite(int n, vector<int> adj[]) {
  queue<int> q;
  vector<int> color(n + 1, -1);

  q.push(1);
  color[1] = 0;

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    for (auto it : adj[node]) {
      if (color[it] == -1) {
        color[it] = !color[node];
        q.push(it);
      } else if (color[it] == color[node]) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> adj[n + 1];

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  if (isBipartite(n, adj)) {
    cout << "Bipartite : Yes";
  } else {
    cout << "Bipartite : No";
  }

  return 0;
}