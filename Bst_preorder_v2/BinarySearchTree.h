#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <algorithm>
#include <cassert>
#include <deque>
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

  // return the index of the first element great than v[i]
  // If no such element, use v.size()
  deque<int> next_greater_idx(deque<int> v) {
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

  // We will improve the previous code by replacing O(n)
  // We know this code just find the next greater element!

  BinarySearchTree(deque<int>& preorder, const deque<int>& next_greater,
                   int start = 0, int end = -1) {
    if (end == -1) end = (int)preorder.size() - 1;

    // next preorder is the current root
    data = preorder[start];

    int split = next_greater[start];

    if (split > end)
      // next is after our end OR doesn't exist, reset our split end
      split = end + 1;

    if (start + 1 <= split - 1)  // there is a left tree
      left = new BinarySearchTree(preorder, next_greater, start + 1, split - 1);
    if (split <= end)
      right = new BinarySearchTree(preorder, next_greater, split, end);
  }

  BinarySearchTree(deque<int>& preorder)
      : BinarySearchTree(preorder, next_greater_idx(preorder)) {}
};

#endif  // !BINARY_SEARCH_TREE
