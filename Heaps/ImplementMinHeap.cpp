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

class minHeap {
public:
  vector<int> heap;

  void insertMinHeap(int val) {
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

  void printMinHeap() {
    for (auto it : heap) {
      cout << it << " ";
    }
  }
};

class maxHeap {
public:
  vector<int> heap;
  void insertMaxHeap(int val) {
    heap.push_back(val);

    int index = heap.size() - 1;

    while (index > 0) {
      int parent = (index - 1) / 2;

      if (heap[parent] < heap[index]) {
        swap(heap[parent], heap[index]);
        index = parent;
      } else {
        break;
      }
    }
  }

  void printMaxHeap() {
    for (auto it : heap) {
      cout << it << " ";
    }
  }
};

int main() {
  minHeap h;
  maxHeap hh;
  h.insertMinHeap(5);
  h.insertMinHeap(10);
  h.insertMinHeap(20);
  h.insertMinHeap(2);
  cout << "MIN HEAP" << endl;
  h.printMinHeap();
  cout << endl;

  cout << "MAX HEAP" << endl;
  hh.insertMaxHeap(5);
  hh.insertMaxHeap(10);
  hh.insertMaxHeap(20);
  hh.insertMaxHeap(2);
  hh.printMaxHeap();

  return 0;
}