#ifndef STACK_H
#define STACK_H

#include <bits/stdc++.h>

#include <stdexcept>

#include "Queue.h"
using namespace std;

class Stack {
 private:
  Queue q;
  int added_elements{0};
  int length;

 public:
  Stack(int size) { length = size; }

  void push(int data) {
    if (isFull()) throw runtime_error("Stack is full!");

    q.enqueue(data);
    int size = added_elements;

    while (size--) q.enqueue(q.dequeue());

    added_elements++;
  }

  int pop() {
    if (isEmpty()) throw runtime_error("Cannot pop an empty stack!");

    added_elements--;
    return q.dequeue();
  }

  int peek() {
    if (isEmpty()) throw runtime_error("Cannot peek an empty stack!");

    return q.front();
  }

  bool isEmpty() { return q.isEmpty(); }

  bool isFull() { return added_elements == length; }
};
#endif
