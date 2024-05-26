#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <utility>
using namespace std;

template <typename T>
class LinkedList {
  struct Node {
   public:
    T data;
    Node* next;
    Node* prev;

    Node(T data) { this->data = data; }
    Node(T data, Node* next, Node* prev) {
      this->data = data;
      this->next = next;
      this->prev = prev;
    }
  };

 public:
  LinkedList() {
    head = nullptr;
    tail = nullptr;
    length = 0;
  }

  LinkedList(const LinkedList&) = delete;
  LinkedList& operator=(const LinkedList& another) = delete;

  void print() const {
    // Time complexity O(n), Space complexity O(1)
    if (!head) cout << "List is empty!" << endl;
    for (Node* walker = head; walker; walker = walker->next) {
      cout << walker->data << " ";
    }

    cout << endl;
  }

  void print_reverse() const {
    // Time complexity O(n), Space complexity O(1)
    if (!tail) cout << "List is empty!" << endl;
    for (Node* walker = tail; walker; walker = walker->prev) {
      cout << walker->data << " ";
    }

    cout << endl;
  }

  void insert_end(T item) {
    // Time complexity O(1), Space complexity O(1)
    Node* newNode = new Node(item, nullptr, nullptr);

    if (!head) {
      head = tail = newNode;
    } else {
      link_nodes(tail, newNode);
      tail = newNode;
    }

    length++;
    debug_verify_data_integrity();
  }

  void insert_front(T item) {
    // Time complexity O(1), Space complexity O(1)
    Node* newNode = new Node(item, nullptr, nullptr);

    if (!head) {
      head = tail = newNode;
    } else {
      link_nodes(newNode, head);
      head = newNode;
    }

    length++;
    debug_verify_data_integrity();
  }

  void insert_sorted(T item) {
    // Time complexity O(n), Space complexity O(1)
    if (!length || item <= head->data)
      insert_front(item);
    else if (tail->data <= item)
      insert_end(item);
    else {
      for (Node* cur = head; cur; cur = cur->next) {
        if (item <= cur->data) {
          Node* newNode = new Node(item);
          link_nodes(cur->prev, newNode);
          link_nodes(newNode, cur);
          length++;
          break;
        }
      }
    }
    debug_verify_data_integrity();
  }

  void delete_front() {
    // Time complexity O(1), Space complexity O(1)
    if (!head) throw runtime_error("Cannot delete in an empty list");

    Node* next = head->next;
    delete head;
    length--;
    head = next;

    if (head)
      head->prev = nullptr;
    else if (!length)
      tail = nullptr;
    debug_verify_data_integrity();
  }

  void delete_end() {
    // Time complexity O(1), Space complexity O(1)
    if (!head) throw runtime_error("Cannot delete in an empty list");

    Node* prev = tail->prev;
    delete tail;
    length--;
    tail = prev;

    if (tail)
      tail->next = nullptr;
    else if (!length)
      head = nullptr;
    debug_verify_data_integrity();
  }

  Node* delete_and_link(Node* cur) {
    Node* nodeToReturn = cur->prev;
    link_nodes(nodeToReturn, cur->next);
    delete cur;
    length--;

    return nodeToReturn;
  }

  void delete_node_with_key(T key) {
    // Time complexity O(n), Space complexity O(1)
    if (!length) throw runtime_error("Cannot delete in an empty list");

    if (head->data == key)
      delete_front();
    else {
      for (Node* cur = head; cur; cur = cur->next) {
        if (cur->data == key) {
          cur = delete_and_link(cur);
          if (!cur->next) tail = cur;
          break;
        }
      }
    }
    debug_verify_data_integrity();
  }

  void delete_all_node_with_key(T key) {
    // Time complexity O(n), Space complexity O(1)
    if (!length) throw runtime_error("Cannot delete in an empty list");

    insert_front(-123);

    for (Node* cur = head; cur;) {
      if (cur->data == key) {
        cur = delete_and_link(cur);

        if (!cur->next) tail = cur;
      } else {
        cur = cur->next;
      }
    }
    delete_front();

    debug_verify_data_integrity();
  }

  void delete_even_positions() {
    // Time complexity O(log n), Space complexity O(1)
    if (!length) throw runtime_error("Cannot delete an empty list!");

    for (Node* cur = head->next; cur;) {
      cur = delete_and_link(cur);
      if (!cur->next) {
        tail = cur;
        break;
      }
      cur = cur->next->next;
    }

    debug_verify_data_integrity();
  }

  void delete_odd_positions() {
    // Time complexity O(log n), Space complexity O(1)
    if (!length) throw runtime_error("Cannot delete an empty list!");

    insert_front(-123);  // Insert dummy

    for (Node* cur = head->next; cur;) {
      cur = delete_and_link(cur);
      if (!cur->next) {
        tail = cur;
        break;
      }
      cur = cur->next->next;
    }
    delete_front();

    debug_verify_data_integrity();
  }

  bool is_palindrome() const {
    // Time complexity O(log n), Space complexity O(1)
    if (!length) return false;

    int count = 1;
    for (Node *cur = head, *rev = tail; count <= length / 2; count++) {
      if (cur->data != rev->data)
        return false;
      else {
        cur = cur->next;
        rev = rev->prev;
      }
    }
    return true;
  }

  // DoublyLinked list implementation
  T find_middle() const {
    // Time complexity O(log n), Space complexity O(1)
    if (!head) throw runtime_error("Cannot search an empty list!");

    Node* start = head;
    Node* end = tail;

    while (start != end && start->next != end) {
      start = start->next;
      end = end->prev;
    }
    return end->data;
  }

  // SinglelyLinked list implementation
  T find_middle2() const {
    // Time complexity O(log n), Space complexity O(1)
    if (!head) throw runtime_error("Cannot search an empty list!");

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    // If length is even
    return slow->data;
  }

  Node* get_nth(int n) {
    int count = 0;
    for (Node* cur = head; cur; cur = cur->next)
      if (++count == n) return cur;

    return nullptr;
  }
  Node* get_nth_back(int n) {
    int count = 0;
    for (Node* cur = tail; cur; cur = cur->prev)
      if (++count == n) return cur;

    return nullptr;
  }

  // Utilizing length in implementation
  void swap_kth(int k) {
    // Time complexity O(k), Space complexity O(1)
    if (!length) throw runtime_error("Cannot swap empty list!");
    if (k < 1) throw runtime_error("Invalid index, k < 1!");
    if (k > length) throw out_of_range("k is out of list range!");

    // Resolve different cases
    int kth_back = length - k + 1;

    if (k == kth_back)  // Same node
      return;

    if (k > kth_back) swap(k, kth_back);

    Node* first = get_nth(k);
    Node* last = get_nth(kth_back);

    Node* first_prev = first->prev;
    Node* first_next = first->next;

    Node* last_prev = last->prev;
    Node* last_next = last->next;

    if (k + 1 == kth_back) {
      link_nodes(first_prev, last);
      link_nodes(last, first);
      link_nodes(first, last_next);
    } else {
      link_nodes(first_prev, last);
      link_nodes(last, first_next);

      link_nodes(last_prev, first);
      link_nodes(first, last_next);
    }

    if (k == 1) swap(head, tail);

    debug_verify_data_integrity();
  }

  // Without length variable
  void swap_kth2(int k) {
    // Time complexity O(k), Space complexity O(1)
    if (!head) throw runtime_error("Cannot swap empty list!");
    if (k < 1) throw runtime_error("Invalid index, k < 1!");

    Node* first = get_nth(k);
    Node* last = get_nth_back(k);

    if (!first || !last) throw out_of_range("k is out of list range!");

    if (first == last) return;  // Same node

    if (first->prev == last) swap(first, last);

    Node* first_prev = first->prev;
    Node* first_next = first->next;

    Node* last_prev = last->prev;
    Node* last_next = last->next;

    if (first->next == last) {
      link_nodes(first_prev, last);
      link_nodes(last, first);
      link_nodes(first, last_next);
    } else {
      link_nodes(first_prev, last);
      link_nodes(last, first_next);

      link_nodes(last_prev, first);
      link_nodes(first, last_next);
    }

    if (k == 1) swap(head, tail);

    debug_verify_data_integrity();
  }

  void reverse() {
    // Time complexity O(n), Space complexity O(1)
    if (!length) throw runtime_error("Cannot reverse empty list!");

    Node* prv = head;
    tail = head;
    head = head->next;

    while (head) {
      Node* next = head->next;
      link_nodes(head, prv);

      // Move to next node
      prv = head, head = next;
    }

    // Integrity change
    head = prv;
    head->prev = tail->next = nullptr;

    debug_verify_data_integrity();
  }

  void merge_2sorted_lists(LinkedList& other) {
    // Time complexity O(n+m), Space complexity O(1)
    if (!other.length) return;

    if (!length) {
      // Copy data
      head = other.head;
      tail = other.tail;
      length = other.length;
    } else {
      Node *main = head, *alt = other.head;

      while (main && alt) {
        if (main->data >= alt->data) {
          Node* next = alt->next;
          if (main == head) {
            head = alt;
            head->prev = nullptr;
          } else {
            link_nodes(main->prev, alt);
          }

          // Insert before the main and move to next alt
          link_nodes(alt, main);
          length++, other.length--;
          alt = next;
        } else {
          // Main length < alt length
          if (main == tail && main->data < alt->data) {
            link_nodes(main, alt);
            tail = other.tail;
            length += other.length;
          }
          main = main->next;
        }
      }
    }

    other.head = other.tail = nullptr;
    other.length = 0;

    debug_verify_data_integrity();
  }

 private:
  Node* head;
  Node* tail;
  int length;

  void link_nodes(Node* first, Node* second) {
    if (first) first->next = second;
    if (second) second->prev = first;
  }

  void debug_verify_data_integrity() {
    if (length == 0) {
      // Empty List integrity
      if (head != nullptr)
        throw runtime_error("List is empty, head is not null!");
      if (tail != nullptr)
        throw runtime_error("List is empty, tail is not null!");
    } else {
      // Non empty list intergrity
      if (head == nullptr)
        throw runtime_error("List is not empty, head is null!");
      if (tail == nullptr)
        throw runtime_error("List is not empty, tail is null!");
      if (length == 1)
        if (head != tail) throw runtime_error("Length is 1, head != tail!");

      if (head->prev) throw runtime_error("Head is not pointing to null!");
      if (tail->next) throw runtime_error("tail is not pointing to null!");
    }
    int len = 0;
    for (Node* cur = head; cur; cur = cur->next, len++) {
      if (len == length - 1)  // make sure we end at tail
        if (cur != tail) throw runtime_error("End node is not tail!");
    }

    if (length != len)
      throw runtime_error("No. of items is not equal to length!");

    len = 0;
    for (Node* cur = tail; cur; cur = cur->prev, len++) {
      if (len == length - 1)  // make sure we end at head
        if (cur != head) throw runtime_error("first node is not head!");
    }
  }
};

#endif
