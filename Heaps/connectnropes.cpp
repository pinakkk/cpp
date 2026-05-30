// Algorithm Put all ropes into a Min Heap.While heap size > 1
//     : Take smallest rope.Take second smallest rope.Add their sum to
//           answer.Push the new rope back into heap. Print answer.

#include <functional>
#include <iostream>
#include <queue>
using namespace std;

int main() {
  int n;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0; i < n; i++) {
    int val;
    cin >> val;
    pq.push(val);
  }

  int cost = 0;

  while (pq.size() > 1) {
    int first = pq.top();
    pq.pop();

    int second = pq.top();
    pq.pop();

    int sum = first + second;
    cost += sum;
    pq.push(sum);
  }
  cout << "Total Cost : " << cost << endl;

  return 0;
}