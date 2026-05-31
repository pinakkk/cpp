#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    arr.push_back(val);
  }

  //   load first k + 1 elements into heap
  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0; i <= k && i < n; i++) {
    pq.push(arr[i]);
  }

  // pop min, push next
  int index = 0;
  for (int i = k + 1; i < n; i++) {
    arr[index++] = pq.top();
    pq.pop();
    pq.push(arr[i]);
  }

  // drain
  while (!pq.empty()) {
    arr[index++] = pq.top();
    pq.pop();
  }

  for (auto it : arr) {
    cout << it << " ";
  }

  return 0;
}