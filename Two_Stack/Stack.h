/*
 * Change stack class to be able to perform the stack operations but simulating
2 stacks in same time. Consider the following constraints.

* Use only the same single array
*
* All operations should have the same old time/memory complexity
*
* Each stack can use as much as possible of available array
* * For example, assume we created stack of 100 elements
* * * The first stack used 20 elements so far
* * * Then the second stack can use up to 80 elements and so on
*
* Change functions similar to following: void push(int id, int x)
* * Id either 1 or 2 to refer to the stack itself

*/

#ifndef STACK_H
#define STACK_H

#include <bits/stdc++.h>

#include <stdexcept>
using namespace std;

class Stack {
 private:
  int size{};
  int top1{};
  int top2{};
  int* array{};

 public:
  Stack(int size) : size(size), top1(-1), top2(size) { array = new int[size]; }

  ~Stack() { delete[] array; }

  void push(int id, int x) {
    if (isFull()) throw runtime_error("Stack is full!");

    if (id == 1)
      array[++top1] = x;
    else
      array[--top2] = x;
  }

  int pop(int id) {
    if (isEmpty(id)) throw runtime_error("Cannot pop an empty stack!");

    int result;
    if (id == 1)
      result = array[top1--];
    else
      result = array[top2++];

    return result;
  }

  int peek(int id) {
    if (isEmpty(id)) throw runtime_error("Cannot peek an empty stack!");

    int result;
    if (id == 1)
      result = array[top1];
    else
      result = array[top2];

    return result;
  }

  bool isFull() { return top1 + 1 >= top2; }

  bool isEmpty(int id) {
    if (id == 1)
      return top1 == -1;
    else
      return top2 == size;
  }

  void display() {
    for (int i = top1; i >= 0; i--) cout << array[i] << " ";
    cout << endl;

    for (int i = top2; i < size; i++) cout << array[i] << " ";
    cout << endl;
  }
};

#endif
