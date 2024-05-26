#include <bits/stdc++.h>

#include <exception>

#include "BinaryTree.h"
using namespace std;

// function definition
void test();

int main() {
  try {
    test();
  } catch (exception& ex) {
    cout << ex.what() << endl;
  }

  return 0;
}

// function implementation
void test() {
  BinaryTree tree(1);
  tree.add({2, 4, 7}, {'L', 'L', 'L'});
  tree.add({2, 4, 8}, {'L', 'L', 'R'});
  tree.add({2, 5, 9}, {'L', 'R', 'R'});
  tree.add({3, 6, 10}, {'R', 'R', 'L'});

  tree.print_inorder();
  // 7 4 8 2 5 9 1 3 10 6
}
