#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include <bits/stdc++.h>

#include <cassert>
#include <queue>
#include <stdexcept>
using namespace std;

class PriorityQueue {
 private:
  struct BinaryNode {
    int priority{};
    int height{};
    // Each node have all task ids of same prioirty
    vector<int> task_ids{};
    BinaryNode* left{};
    BinaryNode* right{};

    BinaryNode(int task_id, int priority) : priority(priority) {
      task_ids.push_back(task_id);
    }

    int ch_height(BinaryNode* node) {  // child height
      if (!node) return -1;            // -1 for null
      return node->height;             // 0 for leaf
    }
    int update_height() {  // call in end of insert function
      return height = 1 + max(ch_height(left), ch_height(right));
    }
    int balance_factor() { return ch_height(left) - ch_height(right); }
  };

  BinaryNode* root{};

  ///////////////////////////
  bool search(int target, BinaryNode* node) {
    if (!node) return false;

    if (target == node->priority) return true;

    if (target < node->priority) return search(target, node->left);

    return search(target, node->right);
  }

  BinaryNode* right_rotation(BinaryNode* Q) {
    BinaryNode* P = Q->left;
    Q->left = P->right;
    P->right = Q;
    Q->update_height();
    P->update_height();
    return P;
  }

  BinaryNode* left_rotation(BinaryNode* P) {
    BinaryNode* Q = P->right;
    P->right = Q->left;
    Q->left = P;
    P->update_height();
    Q->update_height();
    return Q;
  }

  BinaryNode* balance(BinaryNode* node) {
    if (node->balance_factor() == 2) {           // Left
      if (node->left->balance_factor() == -1)    // Left Right?
        node->left = left_rotation(node->left);  // To Left Left

      node = right_rotation(node);  // Balance Left Left
    } else if (node->balance_factor() == -2) {
      if (node->right->balance_factor() == 1)
        node->right = right_rotation(node->right);

      node = left_rotation(node);
    }
    return node;
  }

  BinaryNode* insert_node(int task_id, int priority, BinaryNode* node) {
    if (priority < node->priority) {
      if (!node->left)
        node->left = new BinaryNode(task_id, priority);
      else
        node->left = insert_node(task_id, priority, node->left);
    } else if (priority > node->priority) {
      if (!node->right)
        node->right = new BinaryNode(task_id, priority);
      else
        node->right = insert_node(task_id, priority, node->right);
    } else
      node->task_ids.push_back(task_id);  // existing key
    node->update_height();
    return balance(node);
  }

  BinaryNode* min_node(BinaryNode* cur) {
    while (cur && cur->left) cur = cur->left;
    return cur;
  }

  BinaryNode* max_node(BinaryNode* cur) {
    while (cur && cur->right) cur = cur->right;
    return cur;
  }

  BinaryNode* delete_node(int priority, BinaryNode* node) {
    if (!node) return nullptr;

    if (priority < node->priority)
      node->left = delete_node(priority, node->left);
    else if (priority > node->priority)
      node->right = delete_node(priority, node->right);
    else {
      BinaryNode* tmp = node;

      if (!node->left && !node->right)  // case 1: no child
        node = nullptr;
      else if (!node->right)  // case 2: has left only
        node = node->left;    // connect with child
      else if (!node->left)   // case 2: has right only
        node = node->right;
      else {  // 2 children: Use successor
        BinaryNode* mn = min_node(node->right);
        node->priority = mn->priority;  // copy & go delete
        node->right = delete_node(node->priority, node->right);
        tmp = nullptr;  // Don't delete me. Successor will be deleted
      }
      if (tmp) delete tmp;
    }
    if (node) {
      node->update_height();
      node = balance(node);
    }
    return node;
  }

 public:
  void enqueue(int task_id, int task_priority) {
    if (!root)
      root = new BinaryNode(task_id, task_priority);
    else
      root = insert_node(task_id, task_priority, root);
  }

  int dequeue() {
    if (isempty()) throw runtime_error("Queue is empty!");

    // To keep dequeue O(logn) although node have several tasks
    // We will always push and pop from back in O(1)

    BinaryNode* mx = max_node(root);
    assert(mx->task_ids.size() > 0);
    int ret = mx->task_ids.back();
    mx->task_ids.pop_back();
    if (mx->task_ids.size() == 0) root = delete_node(mx->priority, root);

    return ret;
  }

  bool isempty() { return root == nullptr; }
};

#endif  // !PRIORITY_QUEUE
