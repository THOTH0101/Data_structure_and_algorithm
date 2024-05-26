#ifndef STACK_H
#define STACK_H

#include <bits/stdc++.h>

#include <stdexcept>
using namespace std;

class Stack {
 private:
  int size{};
  int top{};
  int* array{};

 public:
  Stack(int size) : size(size), top(-1) { array = new int[size]; }

  ~Stack() { delete[] array; }

  void push(int x) {
    if (is_full()) throw runtime_error("Stack is full!");

    array[++top] = x;
  }

  int pop() {
    if (isEmpty()) throw runtime_error("Stack is empty!");

    return array[top--];
  }

  int peek() {
    if (isEmpty()) throw runtime_error("Stack is empty!");

    return array[top];
  }

  void insert_at_bottom(int x) {
    // Base call
    if (isEmpty())
      push(x);
    else {
      int cur = pop();

      insert_at_bottom(x);

      push(cur);
    }
  }

  void reverse() {
    if (isEmpty())
      return;
    else {
      int cur = pop();
      reverse();
      insert_at_bottom(cur);
    }
  }

  bool is_full() { return top == size - 1; }

  bool isEmpty() { return top == -1; }

  void display() {
    if (isEmpty()) throw runtime_error("Stack is empty!");

    for (int i = top; i >= 0; i--) cout << array[i] << " ";
    cout << endl;
  }

  void display_reverse() {
    if (isEmpty()) throw runtime_error("Stack is empty!");

    for (int i = 0; i <= top; i++) cout << array[i] << " ";
    cout << endl;
  }
};

#endif
