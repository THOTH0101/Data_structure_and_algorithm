/* Instead of top, used int added_elements to represent number of added elements
 * so far Instead of assert, push, pop, peek ⇒ returns bool to indicate success
 * / failure If we push 10, 20, 30 in stack, the array content is: {30, 20, 10}
 * That is, array[0] represents the top
 */
#ifndef STACK_H
#define STACK_H

#include <bits/stdc++.h>
using namespace std;

class Stack {
 private:
  int size{};
  int added_elements{};
  int* array{};

 public:
  Stack(int size) : size(size) { array = new int[size]; }

  ~Stack() { delete[] array; }

  bool push(int x) {
    if (isFull()) return false;

    for (int i = added_elements; i >= 0; i--) array[i + 1] = array[i];

    array[0] = x;
    added_elements++;
    return true;
  }

  bool pop(int& result) {
    if (isEmpty()) return false;
    result = array[0];

    for (int i = 0; i < added_elements - 1; i++) array[i] = array[i + 1];
    added_elements--;

    return true;
  }

  bool peek(int& result) {
    if (isEmpty()) return false;

    result = array[0];
    return true;
  }

  int isFull() { return added_elements == size; }

  int isEmpty() { return added_elements == 0; }

  void display() {
    for (int i = 0; i < added_elements; i++) cout << array[i] << " ";
    cout << endl;
  }
};

#endif
