#ifndef QUEUE_H
#define QUEUE_H

#include <bits/stdc++.h>

#include <stdexcept>
using namespace std;
class Queue {
 private:
  int* array;
  int length{};
  int front{0};
  int end{0};

  int next(int idx) {
    ++idx;

    if (idx == length) idx = 0;
    return idx;
  }

 public:
  Queue(int size) : length(++size) { array = new int[size]; }

  ~Queue() { delete[] array; }

  void enqueue(int data) {
    if (isFull()) throw runtime_error("Cannot enqueue a full queue!");

    array[end] = data;
    end = next(end);
  }

  int dequeue() {
    if (isEmpty()) throw runtime_error("Cannot dequeue an empty queue!");

    int data = array[front];
    front = next(front);
    return data;
  }

  bool isEmpty() { return end == front; }

  bool isFull() { return next(end) == front; }

  void display() {
    cout << "Front " << front << " - end " << end << "\t";
    if (isFull())
      cout << "full";
    else if (isEmpty()) {
      cout << "empty\n\n";
      return;
    }
    cout << "\n";

    for (int i = front; i != end; i = next(i)) cout << array[i] << " ";
    cout << endl;
  }
};

#endif
