#include <bits/stdc++.h>

#include <cassert>
#include <iostream>

#include "BinarySearchTree.h"
using namespace std;

BinarySearchTree* GetTree4();
void bst_from_preorder();

int main() {
  bst_from_preorder();

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

void bst_from_preorder() {
  BinarySearchTree* tree = GetTree4();

  deque<int> preorder_queue;

  tree->build_preorder(preorder_queue);

  BinarySearchTree new_tree(preorder_queue);
  new_tree.print_inorder();  // must be sorted
}
