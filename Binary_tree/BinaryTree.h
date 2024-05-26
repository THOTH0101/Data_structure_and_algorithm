#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <bits/stdc++.h>

#include <stdexcept>
#include <vector>
using namespace std;

class BinaryTree {
 private:
  struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) { this->data = data; }
  };

  void print_inorder(Node* cur) {
    if (!cur) return;

    print_inorder(cur->left);
    cout << cur->data << " ";
    print_inorder(cur->right);
  }
  Node* root;

 public:
  BinaryTree(int data) { root = new Node(data); }

  void print_inorder() {
    print_inorder(root);
    cout << endl;
  }

  void add(vector<int> data, vector<char> direction) {
    if (data.size() != direction.size())
      throw runtime_error("Incomplete node path!");

    Node* cur = this->root;

    for (int i = 0; i < direction.size(); i++) {
      if (direction[i] == 'L') {
        if (!cur->left)
          cur->left = new Node(data[i]);
        else if (cur->left->data != data[i])
          throw runtime_error(
              "Current node is not equal previous node in the path!");
        cur = cur->left;
      } else {
        if (!cur->right)
          cur->right = new Node(data[i]);
        else if (cur->right->data != data[i])
          throw runtime_error(
              "current node is not eaual previous node in the path!");
        cur = cur->right;
      }
    }
  }
};

#endif
