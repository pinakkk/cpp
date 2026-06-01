#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool bfs(int node, vector<int> adj[], vector<int> &vis) {
  vis[node] = 1;
  queue<pair<int, int>> q;
  q.push({node, -1});

  while (!q.empty()) {
    int node = q.front().first;
    int parent = q.front().second;
    q.pop();

    for (auto it : adj[node]) {
      if (!vis[it]) {
        vis[it] = 1;
        q.push({it, node});
      } else if (it != parent) {
        return true;
      }
    }
  }

  return false;
}

bool hasCycle(int V, vector<int> adj[]) {
  vector<int> vis(V + 1, 0);
  for (int i = 1; i <= V; i++) {
    if (!vis[i]) {
      if (bfs(i, adj, vis))
        return true;
    }
  }
  return false;
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

  if (hasCycle(n, adj)) {
    cout << "has Cycle" << endl;
  } else {
    cout << " Does Not has Cycle " << endl;
  }

  return 0;
}