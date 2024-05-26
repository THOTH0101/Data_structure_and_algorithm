#ifndef STACK_H
#define STACK_H

#include <bits/stdc++.h>

#include <stdexcept>
using namespace std;

template <typename T>
class Stack {
 private:
  struct Node {
    Node* next;
    T data;

    Node(T data, Node* next) {
      this->data = data;
      this->next = next;
    }
  };

  Node* top{};

 public:
  ~Stack() {
    while (!isEmpty()) pop();
  }

  void push(T data) {
    Node* newNode = new Node(data, top);
    top = newNode;
  }

  T pop() {
    if (!top) throw runtime_error("Cannot pop an empty stack!");

    T element = top->data;
    Node* temp = top->next;
    delete top;
    top = temp;

    return element;
  }

  T peek() {
    if (!top) throw runtime_error("Cannot peek an empty stack!");

    T element = top->data;
    return element;
  }

  bool isEmpty() { return top == nullptr; }

  void display() {
    Node* walker = top;

    while (!walker) cout << walker->data << " ";
    cout << endl;
  }
};

#endif
