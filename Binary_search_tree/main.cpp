#include <bits/stdc++.h>

#include <deque>
#include <exception>
#include <utility>
#include <vector>

#include "BinarySearchTree.h"
using namespace std;

void test();
void test1();
void test2();
BinarySearchTree<int>* GetTree();

int main() {
  try {
    // test();
    // test1();
    test2();
  } catch (exception& ex) {
    cout << ex.what() << endl;
  }
}

void test() {
  cout << "-------- start test ---------" << endl;
  BinarySearchTree<int> tree(50);

  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  tree.insert(40);
  tree.insert(60);
  tree.insert(70);
  tree.insert(80);
  tree.insert(90);

  cout << "Nodes in inorder traversal: ";
  for (int i = 1; i <= 9; i++) {
    int j = i;
    cout << tree.kth_smallest(j) << " ";
  }
  cout << endl;
  cout << endl;

  cout << "Is 80 in tree: " << boolalpha << tree.search_iterative(80) << endl;
  cout << "Is tree a BST: " << boolalpha << tree.is_bst1() << endl;

  cout << "--- tree1 ----" << endl;

  vector<int> values = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  BinarySearchTree<int> tree1(values);
  tree1.print_inorder();
  cout << endl;

  cout << "--- tree2 ----" << endl;
  BinarySearchTree tree2(50);
  tree2.insert(20);
  tree2.insert(60);
  tree2.insert(15);
  tree2.insert(45);
  tree2.insert(70);
  tree2.insert(35);
  tree2.insert(73);

  tree2.insert(14);
  tree2.insert(16);
  tree2.insert(36);
  tree2.insert(58);

  cout << "level order printing" << endl;
  tree2.level_order_traversal();
  cout << endl;

  cout << "lowest common ancestor" << endl;
  cout << tree2.lca(35, 60) << "\n";
  cout << tree2.lca(14, 16) << "\n";
  cout << tree2.lca(70, 73) << "\n";

  cout << "-------- end test ---------" << endl << endl;
}

void test1() {
  cout << "-------- start test ---------" << endl;

  BinarySearchTree<int> tree(50);
  tree.insert_with_parent(20);
  tree.insert_with_parent(15);
  tree.insert_with_parent(45);
  tree.insert_with_parent(16);
  tree.insert_with_parent(35);
  tree.insert_with_parent(36);
  tree.insert_with_parent(60);
  tree.insert_with_parent(58);
  tree.insert_with_parent(70);
  tree.insert_with_parent(73);
  tree.insert_with_parent(75);

  tree.level_order_traversal();
  cout << endl;

  vector<int> input = {15, 20, 58};
  cout << "node => successor" << endl;

  for (int i = 0; i < (int)input.size(); i++) {
    cout << input[i];
    pair<bool, int> p = tree.successor(input[i]);

    if (p.first) cout << " => " << p.second << endl;
  }

  cout << "--- queries of ancestors ---" << endl;
  deque<int> queries = {15, 20, 58};
  vector<int> answer, traversal;

  tree.successor_queries(queries, answer, traversal);

  cout << "--- ancestors queries ---" << endl;
  for (int ans : answer) cout << ans << " ";
  cout << endl;

  cout << "--- check for degenerate tree ---" << endl;
  vector<int> a;

  a = {25, 8, 11, 13, 12};
  cout << "25, 8, 11, 13, 12 => " << boolalpha << is_degenerate(a) << endl;

  a = {100, 70, 101};
  cout << "100, 70, 101 => " << boolalpha << is_degenerate(a) << endl;

  a = {100, 70, 60, 75};
  cout << "100, 70, 60, 75 => " << boolalpha << is_degenerate(a) << endl;

  a = {100, 70, 60, 65};
  cout << "100, 70, 60, 65 =>" << boolalpha << is_degenerate(a) << endl;

  a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  cout << "1, 2, 3, 4, 5, 6, 7, 8, 9 => " << boolalpha << is_degenerate(a)
       << endl;

  a = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  cout << "9, 8, 7, 6, 5, 4, 3, 2, 1 => " << boolalpha << is_degenerate(a)
       << endl;

  a = {500, 400, 300, 200, 250, 275, 260};
  cout << "500, 400, 300, 200, 250, 275, 260 => " << boolalpha
       << is_degenerate(a) << endl;

  a = {500, 400, 300, 200, 250, 275, 260, 280};
  cout << "500, 400, 300, 200, 250, 275, 260, 280 => " << boolalpha
       << is_degenerate(a) << endl;

  cout << "--------- end test ----------" << endl << endl;
}

void test2() {
  cout << "-------- start test ---------" << endl;
  deque<int> preorder = {50, 20, 15, 45, 35, 60, 70, 73};
  BinarySearchTree<int> tree(preorder);

  tree.level_order_traversal();

  cout << "---- tree1 ----" << endl;
  cout << "before deletion: ";
  BinarySearchTree<int>* tree1 = GetTree();
  tree1->print_inorder();
  cout << endl;

  cout << "after deletion: ";
  tree1->delete_value(20);
  tree1->print_inorder();
  cout << endl;

  cout << "--------- end test ----------" << endl << endl;
}

BinarySearchTree<int>* GetTree() {
  BinarySearchTree<int>* tree = new BinarySearchTree(50);
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
  return tree;
}
