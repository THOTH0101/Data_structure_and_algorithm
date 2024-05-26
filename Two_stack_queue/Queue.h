#ifndef QUEUE_H
#define QUEUE_H

#include "Stack.h"
using namespace std;

class Queue {
 private:
  int size;
  int added_elements{};
  Stack<int> s1;
  Stack<int> s2;

 public:
  Queue(int size) : added_elements(0) { this->size = size; };

  void enqueue(int data) {
    if (s1.isEmpty())
      s1.push(data);
    else {
      while (!s1.isEmpty()) s2.push(s1.pop());

      s1.push(data);

      while (!s2.isEmpty()) s1.push(s2.pop());
    }
    added_elements++;
  }

  // Time complexity of O(1)
  int dequeue() { return s1.pop(); }

  bool isEmpty() { return s1.isEmpty(); }
};

#endif
