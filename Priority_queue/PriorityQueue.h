#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include <bits/stdc++.h>

#include <iostream>
#include <queue>
#include <stdexcept>
using namespace std;

class PriorityQueue {
 private:
  queue<int> priority1;
  queue<int> priority2;
  queue<int> priority3;
  int added_elements{0};
  int length{};

 public:
  PriorityQueue(int size) : length(size) {}

  void enqueue(int data, int priority) {
    if (isFull()) throw runtime_error("Cannot enqueue a full queue!");

    if (priority == 1)
      priority1.push(data);
    else if (priority == 2)
      priority2.push(data);
    else if (priority == 3)
      priority3.push(data);
    else
      throw runtime_error("Priority is greater than 3");

    added_elements++;
  }

  int dequeue() {
    if (isEmpty()) throw runtime_error("Cannot dequeue an empty queue!");
    int data;
    added_elements--;

    if (!priority3.empty()) {
      data = priority3.front();
      priority3.pop();
    } else if (!priority2.empty()) {
      data = priority2.front();
      priority2.pop();
    } else {
      data = priority1.front();
      priority1.pop();
    }

    return data;
  }

  bool isFull() { return length == added_elements; }

  bool isEmpty() { return added_elements == 0; }
};

#endif
