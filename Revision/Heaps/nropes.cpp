#include <iostream>
#include <queue>
#include <vector>
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
    cost = cost + sum;
    pq.push(sum);
  }

  cout << cost << endl;

  return 0;
}