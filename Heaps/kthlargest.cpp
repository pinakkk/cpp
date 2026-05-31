// Naive Approach :
// Add score
// sort all
// print kth largest

// Approach : Min heap smallest elements stay at top root

// [ 4, 5, 8 ]
// if we enter 2 into it, size becomes greater, so we immediately pop 2 from it,
// so it stays the kth largest which is 3rd largest here;

#include <iostream>
#include <queue>
using namespace std;

int main() {
  int k, n;
  priority_queue<int, vector<int>, greater<int>> pq;
  cin >> k >> n;

  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    pq.push(val);

    if (pq.size() > k) {
      pq.pop();
    }
    if (pq.size() < k) {
      cout << -1 << " " << endl;
    } else {
      cout << pq.top() << " " << endl;
    }
  }

  return 0;
}