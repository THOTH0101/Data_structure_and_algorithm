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

  ////////////////////////////////////////////

  void build_preorder(deque<int>& preorder_queue) {
    preorder_queue.push_back(data);

    if (left) left->build_preorder(preorder_queue);

    if (right) right->build_preorder(preorder_queue);
  }

  // Check if the next element in the preorder is in the range
  bool next_between(deque<int>& preorder, int min, int max) {
    if (preorder.empty()) return false;
    return min < preorder[0] && preorder[0] < max;
  }

  BinarySearchTree(deque<int>& preorder, int min = 0, int max = 1001) {
    data = preorder[0];
    preorder.pop_front();

    // Simply if next node are my left, they must respect my min/max range

    // Compute the next range of left/right nodes
    if (next_between(preorder, min, data))
      left = new BinarySearchTree(preorder, min, data);

    // Now: left subtree has been consumed if any
    if (next_between(preorder, data, max))
      right = new BinarySearchTree(preorder, data, max);
  }
};

#endif  // !BINARY_SEARCH_TREE
