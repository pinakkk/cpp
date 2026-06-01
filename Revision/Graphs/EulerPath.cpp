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

  int odd = 0;

  for (int i = 0; i < n; i++) {
    if (adj[i].size() % 2 != 0) {
      odd++;
    }
  }

  if (odd == 0 || odd == 2) {
    cout << "Euler Path Exists" << endl;
  } else {
    cout << "Euler Path Does Not Exist" << endl;
  }
  return 0;
}
