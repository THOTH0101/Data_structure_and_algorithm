#ifndef ARRAYLINKEDLIST
#define ARRAYLINKEDLIST

#include <iostream>
#include <iterator>
using namespace std;

struct ArrayNode {
  int data;
  int index;
  ArrayNode* next;
  ArrayNode* prev;

  ArrayNode(int data, int index) {
    this->data = data;
    this->index = index;
  }
};

class ArrayLinkedList {
 private:
  ArrayNode* head;
  ArrayNode* tail;
  int length = 0;
  int array_length{};

  void link(ArrayNode* first, ArrayNode* second) {
    if (first) first->next = second;
    if (second) second->prev = first;
  }

  ArrayNode* embed_after(ArrayNode* node_before, int data, int index) {
    ArrayNode* mid = new ArrayNode(data, index);
    length++;

    ArrayNode* node_after = node_before->next;
    link(node_before, mid);

    if (!node_after)
      tail = mid;
    else
      link(mid, node_after);

    return mid;
  }

  ArrayNode* get_index(int index, bool is_create_if_missing) {
    ArrayNode* prev_index = head;

    while (prev_index->next && prev_index->next->index < index)
      prev_index = prev_index->next;

    bool found = prev_index->next && prev_index->next->index == index;

    if (found) return prev_index->next;

    if (!is_create_if_missing) return nullptr;

    return embed_after(prev_index, 0, index);
  }

 public:
  ArrayLinkedList(int array_length) : array_length(array_length) {
    head = tail = new ArrayNode(0, -1);
    length++;
  }

  void set_value(int data, int index) { get_index(index, true)->data = data; }

  void print_array() const {
    ArrayNode* cur = head->next;

    for (int count = 0; count < array_length; count++) {
      if (cur && cur->index == count) {
        cout << cur->data << " ";
        cur = cur->next;
      } else
        cout << "0 ";
    }
    cout << endl;
  }

  void print_array_nonzero() const {
    for (ArrayNode* cur = head->next; cur; cur = cur->next)
      cout << cur->data << " ";
    cout << endl;
  }

  int get_value(int index) {
    ArrayNode* node = get_index(index, false);

    if (!node) return 0;
    return node->data;
  }

  void add(ArrayLinkedList& other) {
    for (ArrayNode* cur = other.head->next; cur; cur = cur->next) {
      ArrayNode* this_index = get_index(cur->index, true);
      this_index->data += cur->data;
    }
  }
};

#endif  // !ARRAYLINKEDLIST
