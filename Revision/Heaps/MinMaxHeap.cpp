#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class minHeap {
public:
  vector<int> heap;

  void insertMinHeap(int value) {
    heap.push_back(value);

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
    cout << "Printing Min Heap..." << endl;
    for (auto it : heap) {
      cout << it << " ";
    }
    cout << endl;
  }
};

class maxHeap {
public:
  vector<int> heap;

  void insertMaxHeap(int value) {
    heap.push_back(value);

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
    cout << "Printing Max Heap..." << endl;
    for (auto it : heap) {
      cout << it << " ";
    }
    cout << endl;
  }

  void heapify(int index, int size) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] > heap[largest]) {
      largest = left;
    }

    if (right < size && heap[right] > heap[largest]) {
      largest = right;
    }

    if (largest != index) {
      swap(heap[index], heap[largest]);
      heapify(largest, size);
    }
  }

  void heapSort() {
    int size = heap.size();

    while (size > 1) {
      swap(heap[0], heap[size - 1]);
      size--;
      heapify(0, size);
    }
  }
};

int main() {
  minHeap h;
  maxHeap mh;

  h.insertMinHeap(2);
  h.insertMinHeap(5);
  h.insertMinHeap(20);
  h.insertMinHeap(10);
  mh.insertMaxHeap(2);
  mh.insertMaxHeap(5);
  mh.insertMaxHeap(20);
  mh.insertMaxHeap(10);

  h.printMinHeap();
  mh.printMaxHeap();

  mh.heapSort();
  mh.printMaxHeap();

  return 0;
}

// Using array we just need to add
//    int heap[100];
//     int size = 0;

//     void insert(int value) {

//         heap[size] = value;
//         int index = size;
//         size++;