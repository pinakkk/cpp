// A Min Heap is a complete binary tree where :

//     Every level is completely filled except possibly the
//         last.The parent is always smaller than its children.

// Parent      = (i - 1) / 2
// Left Child  = 2*i + 1
// Right Child = 2*i + 2

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class Heap {
public:
  vector<int> heap;

  void insert(int val) {
    heap.push_back(val);

    int index = heap.size() - 1;

    while (index > 0) {
      int parent = (index - 1) / 2;
      if (heap[parent] > heap[index]) {
        swap(heap[parent], heap[index]);
        index = parent;
      } else {
        break;
      }
    }
  }

  void print() {
    for (auto it : heap) {
      cout << it << endl;
    }
  }
};

int main() {
  Heap h;
  h.insert(5);
  h.insert(10);
  h.insert(20);
  h.insert(2);
  h.print();
}