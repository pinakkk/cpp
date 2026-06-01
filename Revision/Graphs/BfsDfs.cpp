#include <iostream>
#include <vector>
using namespace std;

vector<int> BFSofGraph(int V, vector<int> adj[]) {
  vector<int> vis(V, 0);

  vis[0] = 1;
  queue<int> q;
  q.push(0);

  vector<int> bfs;

  while (!q.empty()) {
    int node = q.front();
    q.pop();

    bfs.push_back(node);
    for (auto it : adj[node]) {
      if (!vis[it]) {
        vis[it] = 1;
        q.push(it);
      }
    }
  }
  return bfs;
}

void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsList) {
  vis[node] = 1;
  dfsList.push_back(node);
  for (auto it : adj[node]) {
    if (!vis[it]) {
      dfs(it, adj, vis, dfsList);
    }
  }
}

vector<int> DFSofGraph(int V, vector<int> adj[]) {
  vector<int> vis(V, 0);
  int start = 0;
  vector<int> dfsList;
  dfs(start, adj, vis, dfsList);
  return dfsList;
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

  // Printing Adjacency List
  cout << "Adjacency List: " << endl;
  for (int i = 0; i < n; i++) {
    cout << i << " --> ";
    for (auto it : adj[i]) {
      cout << it << " ";
    }
    cout << endl;
  }

  vector<int> bfs = BFSofGraph(n, adj);

  cout << "BFS Traversal: ";
  for (auto node : bfs) {
    cout << node << " ";
  }
  cout << endl;

  cout << "DFS Traversal: ";
  vector<int> dfs = DFSofGraph(n, adj);
  for (auto node : dfs) {
    cout << node << " ";
  }
  cout << endl;

  return 0;
}