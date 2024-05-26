#ifndef QUEUE_H
#define QUEUE_H

#include <bits/stdc++.h>

#include <stdexcept>
using namespace std;

class Deque {
 private:
  int* array{};
  int added_element{0};
  int length{};
  int front;
  int end;

  int next(int idx) {
    idx++;

    if (idx >= length) idx = 0;
    return idx;
  }

  int prev(int idx) {
    idx--;

    if (idx < 0) idx = length - 1;
    return idx;
  }

 public:
  Deque(int size) : length(size) {
    front = end = 0;
    array = new int[size];
  }

  ~Deque() { delete[] array; }

  void enqueue_end(int data) {
    if (isFull()) throw runtime_error("Cannot enqueue a full queue!");

    array[end] = data;
    end = next(end);
    added_element++;
  }

  void enqueue_front(int data) {
    if (isFull()) throw runtime_error("Cannot enqueue a full queue!");

    front = prev(front);
    array[front] = data;
    added_element++;
  }

  int dequeue_front() {
    if (isEmpty()) throw runtime_error("Cannot dequeue an empty queue!");

    int data = array[front];
    front = next(front);
    added_element--;
    return data;
  }

  int dequeue_end() {
    if (isEmpty()) throw runtime_error("Cannot dequeue an empty queue!");
    end = prev(end);

    int data = array[end];
    added_element--;
    return data;
  }

  bool isEmpty() { return added_element == 0; }

  bool isFull() { return added_element == length; }

  void display() {
    cout << "Front " << front << " - End " << end << "\t";
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
