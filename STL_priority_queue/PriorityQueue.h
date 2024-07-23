#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include <stdexcept>

#include "MaxHeap.h"
class PriorityQueue {
 private:
  int capacity{1000};
  int *key{};
  int *value{};
  int size{};

  int left(int node) {
    int p = 2 * node + 1;
    if (p >= size) return -1;
    return p;
  }
  int right(int node) {
    int p = 2 * node + 2;
    return p >= size ? -1 : p;
  }
  int parent(int node) { return node == 0 ? -1 : (node - 1) / 2; }

  void heapify_up(int child_pos) {
    // stop when parent is smaller (or no parent)
    int par_pos = parent(child_pos);
    if (child_pos == 0 || key[par_pos] > key[child_pos]) return;

    swap(key[child_pos], key[par_pos]);
    swap(value[child_pos], value[par_pos]);
    heapify_up(par_pos);
  }

  void heapify_down(int parent_pos) {  // O(logn)
    int child_pos = left(parent_pos);
    int right_child = right(parent_pos);

    if (child_pos == -1)  // no children
      return;
    // is right bigger than left?
    if (right_child != -1 && key[right_child] > key[child_pos])
      child_pos = right_child;

    if (key[parent_pos] < key[child_pos]) {
      swap(key[parent_pos], key[child_pos]);
      swap(value[parent_pos], value[child_pos]);
      heapify_down(child_pos);
    }
  }

 public:
  PriorityQueue() {
    key = new int[capacity]{};
    value = new int[capacity]{};
    size = 0;
  }

  ~PriorityQueue() {
    delete[] key;
    delete[] value;
  }

  int top() {
    if (isempty()) throw runtime_error("Queue is empty!");
    return value[0];
  }

  void enqueue(int data, int priority) {
    if (size + 1 > capacity) throw runtime_error("Queue is full!");
    value[size] = data;
    key[size++] = priority;
    heapify_up(size - 1);
  }

  int dequeue() {
    if (isempty()) throw runtime_error("Queue is empty, Cannot dequeue.");
    int ret = value[0];
    key[0] = key[--size];
    value[0] = value[size];

    heapify_down(0);
    return ret;
  }

  bool isempty() { return size == 0; }
};

#endif  // !PRIORITY_QUEUE
