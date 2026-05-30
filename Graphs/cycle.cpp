#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// O (N + 2E)
// Space O(N)
bool detect(int src, vector<int> adj[], vector<int> &vis) {
  vis[src] = 1;
  queue<pair<int, int>> q;
  q.push({src, -1});

  while (!q.empty()) {
    int node = q.front().first;
    int parent = q.front().second;
    q.pop();

    for (auto adjacentNode : adj[node]) {
      if (!vis[adjacentNode]) {
        vis[adjacentNode] = 1;
        q.push({adjacentNode, node});
      } else if (parent != adjacentNode) {
        return true;
      }
    }
  }

  return false;
}

bool isCycle(int V, vector<int> adj[]) {
  vector<int> vis(V, 0);
  for (int i = 0; i < V; i++) {
    if (!vis[i]) {
      if (detect(i, adj, vis)) {
        return true;
      }
    }
  }
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

  cout << "Adjacency List:\n";
  for (int i = 0; i < n; i++) {
    cout << i << " --> ";
    for (auto it : adj[i]) {
      cout << it << " ";
    }
    cout << endl;
  }

  if (isCycle(n, adj))
    cout << "\nCycle Detected\n";
  else
    cout << "\nNo Cycle Detected\n";

  return 0;
}