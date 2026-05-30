#include <iostream>
#include <vector>
using namespace std;

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

  vector<int> dist(n + 1, -1);

  queue<int> q;
  q.push(1);
  dist[1] = 0;

  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (auto neighbour : adj[node]) {
      if (dist[neighbour] == -1) {
        dist[neighbour] = 1 + dist[node];
        q.push(neighbour);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << dist[i] << " ";
  }

  return 0;
}