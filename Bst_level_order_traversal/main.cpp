#include <bits/stdc++.h>

#include <cassert>
#include <iostream>

#include "BinarySearchTree.h"
using namespace std;

BinarySearchTree* GetTree4();
void bst_from_inorder();

int main() {
  bst_from_inorder();

  cout << "bye\n";

  return 0;
}

BinarySearchTree* GetTree4() {
  BinarySearchTree* tree = new BinarySearchTree(50);
  tree->insert(20);
  tree->insert(60);
  tree->insert(15);
  tree->insert(45);
  tree->insert(70);
  tree->insert(35);
  tree->insert(73);

  tree->insert(14);
  tree->insert(16);
  tree->insert(36);
  tree->insert(58);
  // preorder: 50 20 15 14 16 45 35 36 60 58 70 73
  return tree;
}

BinarySearchTree* GetTree5() {
  BinarySearchTree* tree = new BinarySearchTree(50);
  tree->insert(20);
  tree->insert(60);
  tree->insert(15);
  tree->insert(45);
  tree->insert(55);
  tree->insert(70);
  tree->insert(59);
  return tree;
}

void bst_from_inorder() {
  BinarySearchTree* tree = GetTree5();

  deque<int> queue1 = tree->level_order_traversal();

  BinarySearchTree tree2(queue1);

  deque<int> queue2 = tree2.level_order_traversal();

  assert(queue1 == queue2);

  for (int i = 0; i < queue2.size(); ++i) {
    cout << queue2[i] << " ";
  }
}
