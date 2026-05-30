#include <iostream>
#include <vector>
using namespace std;

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

  cout << "Adj List : " << endl;

  for (int i = 0; i < n; i++) {
    cout << i << " --> ";
    for (auto it : adj[i]) {
      cout << it << " ";
    }
    cout << endl;
  }

  int odd = 0;

  for (int i = 0; i < n; i++) {
    if (adj[i].size() % 2 != 0) {
      odd++;
    }
  }

  if (odd == 0 || odd == 2) {
    cout << "Graph has eular path";
  } else {
    cout << "No eular path";
  }

  return 0;
}

// Easiest Approach

//     For an undirected connected graph :

//     Count vertices with odd degree.If odd count =
//     0 → Eulerian Circuit exists → Eulerian Path exists.If odd count =
//         2 → Eulerian Path exists.Otherwise → No Eulerian Path.

//         Time Complexity : O(V + E)