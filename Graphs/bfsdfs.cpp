#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
  vector<int> vis(V, 0);

  vis[0] = 1;
  queue<int> q;
  q.push(0);

  vector<int> bfs;

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    bfs.push_back(node);

    for (auto i : adj[node]) {
      if (!vis[i]) {
        vis[i] = 1;
        q.push(i);
      }
    }
  }

  return bfs;
}

void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ans) {
  vis[node] = 1;
  ans.push_back(node);
  for (auto it : adj[node]) {
    if (!vis[it]) {
      dfs(it, adj, vis, ans);
    }
  }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
  vector<int> vis(V, 0);
  int start = 0;
  vector<int> dfsList;
  dfs(start, adj, vis, dfsList);
  return dfsList;
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

  vector<int> bfs = bfsOfGraph(n, adj);

  cout << "\nBFS Traversal: ";
  for (auto node : bfs) {
    cout << node << " ";
  }
  cout << endl;

  vector<int> dfs = dfsOfGraph(n, adj);

  cout << "\nDFS Traversal: ";
  for (auto node : dfs) {
    cout << node << " ";
  }
  cout << endl;

  return 0;
}