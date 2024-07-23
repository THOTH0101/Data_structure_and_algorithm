#include <bits/stdc++.h>

#include <exception>

#include "AVLTree.h"
#include "PriorityQueue.h"
using namespace std;

void test();
void test1();
void test_lower();
void test_upper();
void test_priority_queue();
int avl_nodes_rec(int height);

int main() {
  try {
    test();
    test1();
    test_lower();
    test_upper();
    test_priority_queue();
  } catch (exception& ex) {
    cout << ex.what() << endl;
  }

  return 0;
}

void test() {
  cout << "------ start test ------" << endl;
  AVLTree tree;

  vector<int> v{10, 5, 8, 2, 12, 6};
  // vector<int> v { 5, 4, 3, 2, 1};
  cout << "inversion count: " << tree.count_inversion(v) << endl;
  cout << "----- end test -----" << endl << endl;
}

void test1() {
  cout << "------ start test ------" << endl;
  for (int i = 0; i < 10; ++i) {
    cout << i << " " << avl_nodes_rec(i) << "\n" << flush;
  }
  cout << "----- end test -----" << endl << endl;
}

void test_lower() {
  cout << "------ start test ------" << endl;
  AVLTree tree;

  vector<int> v{10, 5, 20, 15, 50, 70, 2, 13, 40};
  // 2, 5, 10, 13, 15, 20, 40, 50, 70

  for (int i = 0; i < v.size(); ++i) tree.insert_value(v[i]);

  sort(v.begin(), v.end());

  for (int i = 0; i < v.size(); ++i)
    cout << v[i] + 1 << " " << tree.lower_bound(v[i] + 1).second << "\n";
  cout << "----- end test -----" << endl << endl;
}

void test_upper() {
  cout << "------ start test ------" << endl;
  AVLTree tree;

  vector<int> v{10, 5, 20, 15, 50, 70, 2, 13, 40};

  for (int i = 0; i < v.size(); ++i) tree.insert_value(v[i]);

  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); ++i)
    cout << v[i] << " " << tree.upper_bound(v[i]).second << "\n";
  cout << "----- end test -----" << endl << endl;
}

void test_priority_queue() {
  cout << "------ start test ------" << endl;
  PriorityQueue tasks;

  tasks.enqueue(1131, 1);
  tasks.enqueue(3111, 3);
  tasks.enqueue(2211, 2);
  tasks.enqueue(3161, 3);
  tasks.enqueue(7761, 7);

  cout << tasks.dequeue() << "\n";  // 7761
  cout << tasks.dequeue() << "\n";  // 3161

  tasks.enqueue(1535, 1);
  tasks.enqueue(2815, 2);
  tasks.enqueue(3845, 3);
  tasks.enqueue(3145, 3);

  // 3145 3845 3111 2815 2211 1535 1131
  while (!tasks.isempty()) cout << tasks.dequeue() << " " << flush;
  cout << endl;
  cout << "----- end test -----" << endl << endl;
}

int avl_nodes_rec(int height) {
  if (height == 0) return 1;
  if (height == 1) return 2;

  return 1 + avl_nodes_rec(height - 1) + avl_nodes_rec(height - 2);
}
