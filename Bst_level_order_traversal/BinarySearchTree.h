#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class BinarySearchTree {
 private:
  int data{};
  BinarySearchTree* left{};
  BinarySearchTree* right{};

 public:
  BinarySearchTree(int data, BinarySearchTree* left = nullptr,
                   BinarySearchTree* right = nullptr)
      : data(data), left(left), right(right) {}

  void print_inorder() {
    if (left) left->print_inorder();

    cout << data << " ";
    if (right) right->print_inorder();
  }

  void insert(int target) {
    if (target < data) {
      if (!left) {
        left = new BinarySearchTree(target);
      } else
        left->insert(target);
    } else if (target > data) {
      if (!right)
        right = new BinarySearchTree(target);
      else
        right->insert(target);
    }  // else: exists already
  }

  // return the index of the first element great than v[i]
  // If no such element, use v.size()
  vector<int> next_greater_idx(vector<int> v) {
    stack<int> pos;

    for (int i = 0; i < (int)v.size(); ++i) {
      while (!pos.empty() && v[i] > v[pos.top()]) {
        v[pos.top()] = i;
        pos.pop();
      }
      pos.push(i);
    }
    // all items in the stack are not answered
    while (!pos.empty()) {
      v[pos.top()] = v.size();
      pos.pop();
    }

    return v;
  }

  ////////////////////////////////////////////

  deque<int> level_order_traversal() {
    queue<BinarySearchTree*> nodes_queue;
    nodes_queue.push(this);
    deque<int> level_order;

    int level = 0;
    while (!nodes_queue.empty()) {
      int sz = nodes_queue.size();

      while (sz--) {
        BinarySearchTree* cur = nodes_queue.front();
        nodes_queue.pop();

        level_order.push_back(cur->data);
        if (cur->left) nodes_queue.push(cur->left);
        if (cur->right) nodes_queue.push(cur->right);
      }
      level++;
    }
    return level_order;
  }

  bool is_bst1() {
    bool left_bst = !left || data > left->data && left->is_bst1();
    bool right_bst = !right || data < right->data && right->is_bst1();
    return left_bst && right_bst;
  }

  // Check if the next element in the preorder is in the range
  bool next_between(deque<int>& level_order, int min, int max) {
    if (level_order.empty()) return false;
    return min < level_order[0] && level_order[0] < max;
  }

  pair<BinarySearchTree*, pair<int, int>> range(BinarySearchTree* node, int mn,
                                                int mx) {
    pair<int, int> range = make_pair(mn, mx);
    return make_pair(node, range);
  }

  BinarySearchTree(deque<int> level_order) {  // O(n)
    // (node, pair [min, max])
    queue<pair<BinarySearchTree*, pair<int, int>>> nodes_queue;

    data = level_order[0];
    level_order.pop_front();
    nodes_queue.push(range(this, 0, 1001));

    // Build the tree level by level as if you are doing level order traversal
    // Use min/max to trivially decide if this node is my left or right
    while (!nodes_queue.empty()) {
      int sz = nodes_queue.size();

      while (sz--) {
        BinarySearchTree* cur = nodes_queue.front().first;
        int min = nodes_queue.front().second.first;
        int max = nodes_queue.front().second.second;
        int data = cur->data;
        nodes_queue.pop();

        // Compute the next range of left & right nodes
        if (next_between(level_order, min, data)) {
          int new_data = level_order[0];
          level_order.pop_front();
          cur->left = new BinarySearchTree(new_data);
          nodes_queue.push(range(cur->left, min, data));
        }

        if (next_between(level_order, data, max)) {
          int new_data = level_order[0];
          level_order.pop_front();
          cur->right = new BinarySearchTree(new_data);
          nodes_queue.push(range(cur->right, data, max));
        }
      }
    }
    assert(is_bst1());
  }
};

#endif  // !BINARY_SEARCH_TREE
