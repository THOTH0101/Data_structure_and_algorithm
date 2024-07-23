#include <bits/stdc++.h>

#include <deque>
#include <exception>
#include <ios>
#include <queue>
#include <utility>

#include "BinaryTree.h"
using namespace std;

// function definition
void test();
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();

int main() {
  try {
    test();
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
  } catch (exception& ex) {
    cout << ex.what() << endl;
  }

  return 0;
}

// function implementation
void test() {
  cout << "----- Start of test -----" << endl;
  BinaryTree<int> tree(1);
  tree.add({2, 4, 7}, {'L', 'L', 'L'});
  tree.add({2, 4, 8}, {'L', 'L', 'R'});
  tree.add({2, 5, 9}, {'L', 'R', 'R'});
  tree.add({3, 6, 10}, {'R', 'R', 'L'});

  tree.print_inorder();
  // 7 4 8 2 5 9 1 3 10 6

  cout << "The max: " << tree.tree_max() << endl;
  cout << "The height: " << tree.tree_height() << endl;
  cout << "The number of nodes in the binary tree: " << tree.total_nodes()
       << endl;
  cout << "The number of node leaf: " << tree.count_leaf() << endl;
  cout << "is 1 in the tree: " << boolalpha << tree.is_exists(1) << endl;
  cout << "is tree a perfect binary tree: " << boolalpha << tree.is_perfect()
       << endl;

  cout << "Printing nodes in left boundary: ";
  tree.traverse_left_boundry();

  cout << "----- End of test -----" << endl << endl;
}

void test1() {
  cout << "----- Start of test -----" << endl;

  BinaryTree<int> tree(2);
  tree.add({3}, {'L'});
  tree.add({13, 8}, {'R', 'R'});
  tree.add({13, 7}, {'R', 'L'});

  tree.print_inorder();
  // 3 2 7 13 8

  cout << "The max: " << tree.tree_max() << endl;
  cout << "The height: " << tree.tree_height() << endl;
  cout << "The number of nodes in the binary tree: " << tree.total_nodes()
       << endl;
  cout << "is 5 in the tree: " << boolalpha << tree.is_exists(5) << endl;
  cout << "is tree a perfect binary tree: " << boolalpha << tree.is_perfect()
       << endl;

  cout << "----- End of test -----" << endl << endl;
}

void test2() {
  cout << "----- Start of test -----" << endl;

  BinaryTree<int> tree(2);
  tree.add({3, 5}, {'L', 'L'});
  tree.add({3, 6}, {'L', 'R'});
  tree.add({13, 7}, {'R', 'L'});
  tree.add({13, 8}, {'R', 'R'});

  tree.print_inorder();
  // 3 2 7 13 8
  cout << "The max: " << tree.tree_max() << endl;
  cout << "The height: " << tree.tree_height() << endl;
  cout << "The number of nodes in the binary tree: " << tree.total_nodes()
       << endl;
  cout << "is 8 in the tree: " << boolalpha << tree.is_exists(8) << endl;
  cout << "is tree a perfect binary tree: " << boolalpha << tree.is_perfect()
       << endl;
  cout << "Printing using iterative inorder: " << endl;
  cout << "tree datas are: ";
  tree.print_inorder_iterative();

  cout << "----- End of test -----" << endl << endl;
}

void test3() {
  cout << "----- Start of test -----" << endl;

  BinaryTree<int> tree(2);
  tree.add({3, 5, 8, 6, 7, 15}, {'L', 'L', 'R', 'R', 'L', 'R'});
  tree.add({13, 8}, {'R', 'L'});
  tree.add({13, 7}, {'R', 'R'});

  tree.print_inorder();

  cout << "nodes of tree left boundary: ";
  tree.traverse_left_boundry();

  cout << "tree diamater: " << tree.tree_diameter().first
       << ", height: " << tree.tree_diameter().second << endl;

  cout << "----- End of test -----" << endl << endl;
}

void test4() {
  cout << "----- Start of test -----" << endl;

  cout << "Using expression tree" << endl;
  BinaryTree<string> tree("23+4*");
  cout << "Postfix expression: ";
  tree.print_postorder();
  cout << "infix expression: ";
  tree.print_inorder_expression();

  cout << "--- tree1 ---" << endl;
  BinaryTree<string> tree1("4321^5-678*+^*+9-");
  cout << "Postfix expression: ";
  tree1.print_postorder();
  cout << "infix expression: ";
  tree1.print_inorder_expression();

  cout << "----- End of test -----" << endl << endl;
}

void test5() {
  cout << "----- Start of test -----" << endl;

  deque<int> inorder = {
      5, 4, 2, 1, 6, 3, 8, 7,
  };

  deque<int> preorder = {1, 2, 4, 5, 3, 6, 7, 8};

  BinaryTree<int> tree(preorder, inorder);

  cout << "Printing preorder:" << endl;
  tree.print_inorder();

  cout << "\nPrinting in nodes level order" << endl;
  tree.level_order_traversal_recursive();

  cout << "\nPrinting in nodes spiral level order" << endl;
  tree.level_order_traversal_spiral();

  cout << "----- End of test -----" << endl << endl;
}

void test6() {
  cout << "----- Start of test -----" << endl;
  cout << "Testing tree generation functions" << endl;
  queue<pair<int, int>> preorder;
  preorder.push(make_pair(1, 0));
  preorder.push(make_pair(2, 0));
  preorder.push(make_pair(4, 1));
  preorder.push(make_pair(5, 1));
  preorder.push(make_pair(3, 0));
  preorder.push(make_pair(6, 1));
  preorder.push(make_pair(7, 1));

  BinaryTree<int> tree(preorder);
  tree.print_preorder();
  tree.level_order_traversal_recursive();

  cout << "--- Second tree ---" << endl;
  queue<pair<int, int>> preorder1;
  preorder1.push(make_pair(2, 0));
  preorder1.push(make_pair(3, 1));
  preorder1.push(make_pair(13, 0));
  preorder1.push(make_pair(7, 1));
  preorder1.push(make_pair(8, 1));

  BinaryTree<int> tree1(preorder1);
  tree1.print_preorder();
  tree1.level_order_traversal_recursive();
  cout << "----- End of test -----" << endl << endl;
}

void test7() {
  cout << "----- Start of test -----" << endl;

  deque<int> preorder = {1, 2, 4, 5, 3, 6, 7};
  deque<int> inorder = {4, 2, 5, 1, 6, 3, 7};

  BinaryTree<int> tree(preorder, inorder);

  tree.level_order_traversal_recursive();
  cout << "Is tree symmetric: " << boolalpha << tree.is_mirror() << endl;

  cout << "--- tree1 ---" << endl;
  deque<int> pre = {1, 2, 3, 5, 6, 4, 7, 8, 2, 4, 8, 7, 3, 6, 5};
  deque<int> in = {
      5, 3, 6, 2, 7, 4, 8, 1, 8, 4, 7, 2, 6, 3, 5,
  };

  BinaryTree<int> tree1(pre, in);

  tree1.level_order_traversal_recursive();
  cout << "Is tree1 symmetric: " << boolalpha << tree1.is_mirror() << endl;

  cout << "--- tree2 ---" << endl;
  deque<int> pre1 = {1, 2, 3, 4, 2, 3, 5, 6, 7, 8, 9, 6, 7, 8, 9};
  deque<int> in1 = {
      3, 2, 1, 3, 2, 4, 7, 6, 8, 9, 5, 7, 6, 8, 9,
  };

  BinaryTree<int> tree2(pre1, in1);

  cout << "Print duplicate subtrees:" << endl;
  tree2.print_duplicate_subtrees();

  cout << "Print in Level order tranversal:" << endl;
  tree2.level_order_traversal_sorted();

  cout << "----- End of test -----" << endl << endl;
}
