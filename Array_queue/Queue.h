#ifndef QUEUE_H
#define QUEUE_H

#include <bits/stdc++.h>

#include <stdexcept>
using namespace std;

class Queue {
 private:
  int* array{};
  int added_element{0};
  int length{};
  int front;
  int end;

  int next(int idx) {
    idx++;

    if (idx == length) idx = 0;
    return idx;
  }

 public:
  Queue(int size) : length(size) {
    front = end = 0;
    array = new int[size];
  }

  ~Queue() { delete[] array; }

  void enqueue(int data) {
    if (isFull()) throw runtime_error("Cannot enqueue a full queue!");

    array[end] = data;
    end = next(end);
    added_element++;
  }

  int dequeue() {
    if (isEmpty()) throw runtime_error("Cannot dequeue an empty queue!");

    int data = array[front];
    front = next(front);
    added_element--;
    return data;
  }

  bool isEmpty() { return added_element == 0; }

  bool isFull() { return added_element == length; }

  void display() {
    cout << "Front " << front << " - end " << end << "\t";
    if (isFull())
      cout << "full";
    else if (isEmpty()) {
      cout << "empty\n\n";
      return;
    }
    cout << "\n";

    for (int i = front, idx = 0; idx < added_element; idx++, i = next(i))
      cout << array[i] << " ";
    cout << endl;
  }
};

#endif
