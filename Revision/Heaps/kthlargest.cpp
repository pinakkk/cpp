#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {

  int k, n;
  cin >> k >> n;

  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    pq.push(val);

    if (pq.size() > k) {
      pq.pop();
    }
    if (pq.size() < k) {
      cout << -1 << " ";
    } else {
      cout << pq.top() << " ";
    }
  }
}