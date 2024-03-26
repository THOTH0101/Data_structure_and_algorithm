#ifndef NODE_H
#define NODE_H

class Node {
 public:
  Node(int data) { this->data = data; }

  Node(int data, Node* next) {
    this->data = data;
    this->next = next;
  }

  int getData() { return data; }

  Node* getNext() { return next; }

  void setData(int data) { this->data = data; }

  void setNext(Node* next) { this->next = next; }

 private:
  int data;
  Node* next;
};

#endif
