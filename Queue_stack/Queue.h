#ifndef QUEUE_H
#define QUEUE_H

#include <bits/stdc++.h>

#include <stdexcept>
using namespace std;
class Queue {
 private:
  struct Node {
   public:
    int data;
    Node* next;

    Node(int data, Node* next) {
      this->data = data;
      this->next = next;
    }
  };

  Node* head{};
  Node* tail{};
  int size;

 public:
  Queue() : head(nullptr), tail(nullptr) { size = 0; }

  ~Queue() {
    head = tail = nullptr;
    size = 0;
  }

  void enqueue(int data) {
    Node* newNode = new Node(data, nullptr);

    if (!head)
      head = tail = newNode;
    else {
      tail->next = newNode;
      tail = newNode;
    }
    size++;
  }

  int dequeue() {
    if (isEmpty()) throw runtime_error("Cannot dequeue an empty queue!");

    int data = head->data;
    head = head->next;
    size--;
    return data;
  }

  int front() {
    if (isEmpty()) throw runtime_error("Queue is empty!");

    int data = head->data;
    return data;
  }

  bool isEmpty() { return head == nullptr; }

  void display() {
    if (isEmpty()) cout << "Queue is empty!" << endl;

    for (Node* cur = head; cur; cur = cur->next) cout << cur->data << " ";
    cout << endl;
  }
};

#endif
