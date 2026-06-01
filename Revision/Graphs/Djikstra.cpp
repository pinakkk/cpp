#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> adj[n + 1];

  for (int i = 0; i < m; i++) {
    int u, v, wt;
    cin >> u >> v >> wt;
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
  }

  // Dijkstra's
  int src = 1;
  vector<int> dist(n + 1, 1e9);
  dist[src] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  pq.push({0, src});

  while (!pq.empty()) {
    int d = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    for (auto it : adj[node]) {
      int adjNode = it.first;
      int wt = it.second;
      if (dist[node] + wt < dist[adjNode]) {
        dist[adjNode] = dist[node] + wt;
        pq.push({dist[adjNode], adjNode});
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << dist[i] << " ";
  }
  return 0;
}