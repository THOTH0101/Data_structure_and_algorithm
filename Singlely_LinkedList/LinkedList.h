// Note: assert was use for all error case instead of proper error handling
// just for simplicity sake error should be handled properly
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <algorithm>
#include <cassert>
#include <climits>
#include <ios>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

#include "Node.h"
using namespace std;

class LinkedList {
 public:
  LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
  }

  ~LinkedList() {
    // Time complexity O(n), memory complexity O(1)
    while (!head) {
      Node* next = head->getNext();
      delete head;
      head = next;
    }
    size = 0;
  }

  LinkedList(const LinkedList&) = delete;

  LinkedList& operator=(const LinkedList& another) = delete;

  int get_size() const {
    // Time complexity O(1), memory complexity O(1)
    return size;
  }

  bool is_empty() const {
    // Time complexity O(1), memory complexity O(1)
    return size == 0;
  }

  void print() const {
    // Time complexity O(n), memory complexity O(1)
    for (Node* temp = head; temp; temp = temp->getNext()) {
      cout << temp->getData() << " ";
    }
    cout << endl;
  }

  void insert_end(int value) {
    // Time complexity O(1), memory complexity O(1)
    Node* temp = new Node(value, nullptr);

    // If list is empty
    if (head == nullptr) {
      head = tail = temp;
    } else {
      tail->setNext(temp);
      tail = temp;
    }
    size++;
  }

  void insert_front(int value) {
    // Time complexity O(1), memory complexity O(1)
    Node* temp = new Node(value, head);

    if (head == nullptr) {
      tail = head = temp;
    } else {
      head = temp;
    }

    size++;
  }

  void insert_sorted(int value) {
    // Time complexity O(n), memory complexity O(1)
    if (!size || value <= head->getData()) {
      // Insert at the head
      insert_front(value);
    } else {
      for (Node *temp = head, *prev = nullptr; temp; temp = temp->getNext()) {
        if (temp->getData() > value) {
          Node* newNode = new Node(value, temp);
          prev->setNext(newNode);
          size++;
          return;
        }
        prev = temp;
      }
    }

    // if value is greater than all value in list
    if (value >= tail->getData()) {
      insert_end(value);
    }
  }

  void delete_front() {
    // Time complexity O(1), memory complexity O(1)
    assert(head != nullptr);

    Node* next = head->getNext();
    delete head;
    head = next;

    size--;
  }

  void delete_end() {
    // Time complexity O(n), memory complexity O(1)
    assert(head != nullptr);
    Node* prev = nullptr;

    for (Node* temp = head; temp; temp = temp->getNext()) {
      if (temp == tail) break;
      prev = temp;
    }

    prev->setNext(nullptr);
    delete tail;
    tail = prev;

    size--;
  }

  void delete_node_with_key(int value) {
    // Time complexity O(n), memory complexity O(1)
    assert(head != nullptr);

    if (head->getData() == value) {
      delete_front();
    } else {
      for (Node *temp = head, *prev = nullptr; temp->getNext() != nullptr;
           temp = temp->getNext()) {
        if (temp->getData() == value) {
          prev->setNext(temp->getNext());
          delete temp;
          size--;
          return;
        }
        prev = temp;
      }
    }

    if (tail->getData() == value) {
      delete_end();
    }
  }

  void delete_even_position() {
    // Time complexity O(n), memory complexity O(1)
    assert(size > 1);
    int count = 1;

    for (Node *temp = head, *prev = nullptr; temp; count++) {
      Node* next = temp->getNext();

      if (count % 2 == 0) {
        // Special if tail is even
        if (temp == tail) {
          tail = prev;
          tail->setNext(nullptr);
          delete temp;
          size--;
          return;
        }
        prev->setNext(temp->getNext());
        delete temp;
        size--;
      }

      prev = temp;
      temp = next;  // Move to the next node
    }
  }

  Node* get_nth(int n) const {
    // Time complexity O(n), memory complexity O(1)
    assert(head != nullptr);

    int idx = 0;

    for (Node* temp = head; temp; temp = temp->getNext(), idx++) {
      if (idx == n) return temp;
    }

    return nullptr;
  }

  Node* get_front_nth(int n) const {
    // Time complexity O(n), memory complexity O(1)
    assert(head != nullptr);

    int position = size - n - 1;
    int idx = 0;

    for (Node* temp = head; temp; temp = temp->getNext(), idx++) {
      if (idx == position) return temp;
    }
    return nullptr;
  }

  int search(int value) const {
    // Time complexity O(n), memory complexity O(1)
    assert(head != nullptr);

    int idx = 0;

    for (Node* temp = head; temp; temp = temp->getNext(), idx++) {
      if (temp->getData() == value) return idx;
    }

    return -1;  // Not found
  }

  int improved_search(int value) {
    // Time complexity O(n), memory complexity O(1)
    assert(head != nullptr);

    int idx = 0;

    for (Node *temp = head, *prev = nullptr; temp;
         temp = temp->getNext(), idx++) {
      if (temp->getData() == value) {
        if (!prev) return idx;
        swap(temp, prev);

        return idx - 1;
      }
      prev = temp;
    }
    return -1;  // Not found
  }

  bool is_same(const LinkedList& secondList) const {
    // Time complexity O(n), memory complexity O(1)
    if (secondList.get_size() != get_size()) return false;

    Node* l1 = head;
    Node* l2 = secondList.head;

    while (l1 && l2) {
      if (l1->getData() != l2->getData()) return false;

      l1 = l1->getNext();
      l2 = l2->getNext();
    }
    return true;  // List is the same
  }

  void swap_pairs() {
    // Time complexity O(n), memory complexity O(1)
    int count = 1;

    for (Node *temp = head, *prev = nullptr; temp; temp = temp->getNext()) {
      if (count % 2 == 0) {
        swap(temp, prev);
      }

      prev = temp;
      count++;
    }
  }

  void reverse() {
    // Time complexity O(n), memory complexity O(1)
    assert(head != nullptr);

    Node *rev = nullptr, *next = nullptr;

    // Walk through the List
    while (head) {
      next = head->getNext();  // Copy the next node before override

      if (!rev) {
        rev = head;
        rev->setNext(nullptr);
        tail = rev;
      } else {
        Node* temp = head;
        temp->setNext(rev);
        rev = temp;
      }

      head = next;
    }
    head = rev;
  }

  void swap_head_and_tail() {
    // Time complexity O(n), memory complexity O(1)
    assert(head != nullptr && head->getNext() != nullptr);

    Node* walker = head;
    Node* beforeTail = nullptr;
    Node* afterHead = head->getNext();

    // Walk to tail of the List
    while (walker != tail) {
      beforeTail = walker;
      walker = walker->getNext();
    }

    // Make head the tail
    head->setNext(nullptr);
    beforeTail->setNext(head);
    tail = head;

    // Make tail the head
    walker->setNext(afterHead);  // Current tail move to front
    head = walker;
  }

  void left_rotate(int k) {
    // Time complexity O(n), memory complexity O(1)
    assert(head != nullptr || k % size == 0);

    k %= size;  // To remove useless circle

    Node* nth = get_nth(k);

    tail->setNext(head);  // Create cycle

    // Reset head and tail
    head = nth->getNext();
    tail = nth;

    tail->setNext(nullptr);  // Disconnect cycle
  }

  void remove_duplicate() {
    // Time complexity O(n^2), memory complexity O(1)
    assert(head != nullptr);

    for (Node* walker = head; walker; walker = walker->getNext()) {
      for (Node *cur = walker->getNext(), *prev = walker; cur;) {
        Node* next = cur->getNext();

        if (walker->getData() == cur->getData()) {
          if (cur == tail) {
            prev->setNext(nullptr);
            tail = prev;
            delete cur;
            size--;
          } else {
            prev->setNext(cur->getNext());
            delete cur;
            size--;
          }
        } else {
          prev = cur;
        }
        cur = next;
      }
    }
  }

  void remove_last_occurance(int key) {
    // Time complexity O(n), memory complexity O(1)
    assert(head != nullptr);

    Node* node_before = nullptr;
    bool found = false;

    for (Node *walker = head, *prev = nullptr; walker;
         prev = walker, walker = walker->getNext()) {
      if (key == walker->getData()) {
        found = true;
        node_before = prev;
      }
    }

    // Delete the last occurance
    if (node_before) {
      if (node_before->getNext() == tail) {
        delete node_before->getNext();
        node_before->setNext(nullptr);
        tail = node_before;
        size--;
      } else {
        Node* node_to_delete = node_before->getNext();
        node_before->setNext(node_to_delete->getNext());
        delete node_to_delete;
        size--;
      }
    } else {
      delete_front();
    }
  }

  void move_to_back(int key) {
    // Time complexity O(n), memory complexity O(1)
    assert(size > 1);

    Node* original_tail = tail;

    for (Node *walker = head, *prev = nullptr; walker != original_tail;) {
      Node* next = walker->getNext();

      if (walker->getData() == key) {
        if (walker == head) {
          head = walker->getNext();  // New head
          tail->setNext(walker);
          walker->setNext(nullptr);
          tail = walker;
        } else {
          prev->setNext(walker->getNext());
          tail->setNext(walker);
          walker->setNext(nullptr);
          tail = walker;
        }
      } else {
        prev = walker;
      }

      walker = next;
    }
  }

  int max() {
    // Time complexity O(1), memory complexity O(1)
    Node* walker = head;
    int max = 0;

    return this->max(walker, max);
  }

  // Recursive helper function
  int max(Node* node, int max) {
    // Time complexity O(n), memory complexity O(1)
    if (node == nullptr) {
      return max;
    }

    if (node->getData() > max) {
      max = node->getData();
    }

    return this->max(node->getNext(), max);
  }

  int max2(Node* head = nullptr, bool is_first_call = true) {
    // Time complexity O(n), memory complexity O(1)
    if (is_first_call) {
      return this->max(this->head, false);
    }

    if (head == nullptr) return INT_MIN;
    return std::max(head->getData(), this->max(head->getNext(), false));
  }

  void arrange_odd_and_even() {
    // Time complexity O(n), memory complexity O(1)
    assert(size > 2);

    Node* cur_odd = head;
    Node* first_even = head->getNext();

    while (cur_odd->getNext() && cur_odd->getNext()->getNext()) {
      Node* next_even = cur_odd->getNext();

      // Link odds
      cur_odd->setNext(cur_odd->getNext()->getNext());
      // Link evens
      next_even->setNext(next_even->getNext()->getNext());

      cur_odd = cur_odd->getNext();

      if (size % 2 == 1) tail = next_even;
    }

    // Relink evens and odds
    cur_odd->setNext(first_even);
  }

  void insert_alternate(LinkedList& another) {
    // Time complexity O(n), memory complexity O(1)
    // Check if another list is empty
    if (!another.size) return;

    // Check if main list is empty
    if (!size) {
      head = another.head;
      tail = another.tail;
      size = another.size;
    } else {
      // If both list are not empty
      Node* alt = another.head;

      for (Node* main = head; main && alt;) {
        Node* next = alt->getNext();

        // Insert another list node in the main List
        if (main && alt) {
          alt->setNext(main->getNext());
          main->setNext(alt);
          size++;
          another.size--;
        }

        alt = next;  // Move to the next alternate list node

        if (main == tail) {
          tail = another.tail;
          main->getNext()->setNext(alt);
          size += another.size;
          break;
        }
        main = main->getNext()->getNext();
      }
    }

    another.head = another.tail = nullptr;
    another.size = 0;
  }

  void add_num(LinkedList& another) {
    // let X = max(length, another.length)
    // let Y = max(length, another.length) - min(length, another.length)
    // O(X) time,  O(Y) memory
    if (another.head == nullptr) return;

    Node* main = head;
    Node* alt = another.head;
    int carry = 0;
    int value1, value2;

    while (main || alt) {
      value1 = 0, value2 = 0;
      if (main) {
        value1 = main->getData();
      }

      if (alt) {
        value2 = alt->getData();
        alt = alt->getNext();
      }

      value1 += value2 + carry;
      carry = value1 / 10;
      value1 %= 10;

      if (main) {
        main->setData(value1);
        main = main->getNext();
      } else {
        insert_end(value1);
      }
    }

    if (carry) {
      insert_end(carry);
    }
  }

  void remove_all_repeated() {
    // Time complexity O(n), Space complexity O(1)
    if (size <= 1) return;

    // Add dummy head for easier prev linking
    insert_front(-123);

    tail = head;
    Node* prev = head;
    Node* cur = head->getNext();

    while (cur) {
      // 2 cases either blocks repeated or not
      bool node_removed = false;

      while (cur && cur->getNext() &&
             cur->getData() == cur->getNext()->getData()) {
        int data_to_delete = cur->getData();
        node_removed = true;

        while (cur && (cur->getData() == data_to_delete)) {
          Node* next = cur->getNext();
          delete cur;
          cur = next;
        }
      }

      if (node_removed) {
        if (!cur) tail = prev;
        prev->setNext(cur);
        prev = cur;
      } else {
        tail = cur;
        prev = cur;
        cur = cur->getNext();
      }
    }

    prev = head->getNext();  // Actual head
    delete_front();          // Remove dummy head
    head = prev;

    // All nodes are repeated
    if (!head) tail = head;
  }

  pair<Node*, pair<Node*, Node*>> reverse_subchain(Node* cur_head, int k) {
    // Time complexity O(n), Space complexity O(1)
    Node* cur_tail = cur_head;
    Node* prv = cur_head;
    cur_head = cur_head->getNext();

    for (int i = 0; i < k - 1 && cur_head; i++) {
      // Relink chain as you move along the node
      Node* next = cur_head->getNext();
      cur_head->setNext(prv);

      // Move to the next node
      prv = cur_head;
      cur_head = next;
    }
    return make_pair(prv, make_pair(cur_tail, cur_head));
  }

  void reverse_chain(int k) {
    if (size <= 1 || k == 1) return;

    Node* temp_head = head;
    Node* last_tail = nullptr;
    head = nullptr;

    while (temp_head) {
      pair<Node*, pair<Node*, Node*>> reverse = reverse_subchain(temp_head, k);
      Node* chain_head = reverse.first;
      Node* chain_tail = reverse.second.first;
      temp_head = reverse.second.second;
      tail = chain_tail;

      if (!head)
        // First reverse chain
        head = chain_head;
      else
        // Link the chains
        last_tail->setNext(chain_head);
      last_tail = chain_tail;
    }

    tail->setNext(nullptr);
  }

 private:
  Node* head;
  Node* tail;
  int size;

  // Helper functions

  void swap(Node* first, Node* second) {
    int temp = first->getData();
    first->setData(second->getData());
    second->setData(temp);
  }

  bool check_consecutive_k(Node* node, int k) {
    int count = 1;

    for (Node* walker = node; walker; walker = walker->getNext(), count++) {
      if (count == k) {
        return true;
      }
    }
    return false;
  }
};

#endif
