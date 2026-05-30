// An array is called almost sorted(or k - sorted) if every element is at most k
//     positions away from its correct position
//     Example Original Sorted Array : 1 2 3 4 5 6 7

//     Almost Sorted Array(k = 2) : 3 1 2 5 4 6 7

//     Notice :

//     3 should be at index 2 but is at index
//     0(2 positions away)1 should be at index 0 but is at index 1(1 position
//     away)

//         No element is more than 2 positions away.

// Idea Put first k +
//     1 elements into Min Heap.Extract minimum and place it in
//         answer.Insert next array element into
//             heap.Repeat.Finally remove all remaining heap elements.

#include <functional>
#include <iostream>
#include <queue>
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

  // for K + 1 elements
  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0; i <= k && i < n; i++) {
    pq.push(arr[i]);
  }

  int index = 0;
  for (int i = k + 1; i < n; i++) {
    arr[index++] = pq.top();
    pq.pop();
    pq.push(arr[i]);
  }

  while (!pq.empty()) {
    arr[index++] = pq.top();
    pq.pop();
  }

  for (auto it : arr) {
    cout << it << " ";
  }

  return 0;
}