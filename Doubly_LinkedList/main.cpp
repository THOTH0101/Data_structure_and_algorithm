#include <bits/stdc++.h>

#include <ios>

#include "LinkedList.h"
using namespace std;

void test();

int main() {
  try {
    test();
  } catch (runtime_error& ex) {
    cout << ex.what() << endl;
  }

  return 0;
}

void test() {
  LinkedList<int> list;
  cout << "Insert item at end of list" << endl;
  list.insert_end(7);
  list.insert_end(5);
  list.insert_end(1);
  list.insert_end(2);
  list.print();

  cout << "Print list in reverse: ";
  list.print_reverse();

  LinkedList<int> list1;
  cout << "Insert item to the front of list" << endl;
  list1.insert_front(9);
  list1.insert_front(7);
  list1.insert_front(5);
  list1.insert_front(3);
  list1.insert_front(1);
  list1.insert_front(0);
  list1.print();

  cout << "Insert item and sort" << endl;
  list1.insert_sorted(-2);
  list1.insert_sorted(4);
  list1.insert_sorted(6);
  list1.insert_sorted(12);
  list1.print();

  cout << "delete node from front in list" << endl;
  list.delete_front();
  list.print();
  cout << "delete node from front in list1" << endl;
  list1.delete_front();
  list1.print();

  cout << "delete node at end of list" << endl;
  list1.delete_end();
  list1.print();

  cout << "delete 5 from list1" << endl;
  list1.delete_node_with_key(5);
  list1.print();

  cout << "\nDeletion Test" << endl;
  LinkedList<char> alpha;
  alpha.insert_end('a');
  alpha.insert_end('a');
  alpha.insert_end('b');
  alpha.insert_end('d');
  alpha.insert_end('u');
  alpha.insert_end('l');
  alpha.insert_end('w');
  alpha.insert_end('a');
  alpha.insert_end('h');
  alpha.insert_end('a');
  alpha.insert_end('b');
  alpha.insert_end('a');
  alpha.insert_end('a');
  alpha.print();
  cout << "After deleting all node with \'a\': ";
  alpha.delete_all_node_with_key('a');
  alpha.print();

  cout << "\nDelete even nodes in position" << endl;
  cout << "Before deletion: ";
  list1.insert_end(11);
  list1.insert_end(21);
  list1.insert_end(13);
  list1.insert_end(10);
  list1.insert_end(31);
  list1.print();
  cout << "After deletion: ";
  list1.delete_even_positions();
  list1.print();
  cout << "Delete odd nodes in position" << endl;
  cout << "Before deletion: ";
  list1.print();
  cout << "After deletion: ";
  list1.delete_odd_positions();
  list1.print();

  cout << "\nCheck for palidrome" << endl;
  LinkedList<int> list2;
  list2.insert_end(1);
  list2.insert_end(2);
  list2.insert_end(3);
  list2.insert_end(4);
  list2.insert_end(3);
  list2.insert_end(2);
  list2.insert_end(1);
  list2.print();
  cout << "is list2 a palindrome: " << boolalpha << list2.is_palindrome()
       << endl;

  list.print();
  cout << "is list a palindrome: " << boolalpha << list.is_palindrome() << endl;

  cout << "\nfind middle in list: ";
  alpha.delete_end();
  alpha.print();
  cout << "middle is " << alpha.find_middle() << endl;

  cout << "Swap forward with backward nth positon" << endl;
  alpha.print();
  cout << "Result: ";
  alpha.swap_kth2(4);
  alpha.print();

  cout << "\nReverse all node" << endl;
  alpha.print();
  cout << "Result: ";
  alpha.reverse();
  alpha.print();

  cout << "\nMerge two sorted lists" << endl;
  cout << "list3: ";
  LinkedList<int> list3;
  list3.insert_sorted(10);
  list3.insert_sorted(30);
  list3.insert_sorted(20);
  list3.insert_sorted(40);
  list3.insert_sorted(50);
  list3.print();

  cout << "list4: ";
  LinkedList<int> list4;
  list4.insert_sorted(17);
  list4.insert_sorted(15);
  list4.insert_sorted(22);
  list4.insert_sorted(24);
  list4.insert_sorted(35);
  list4.print();

  cout << "After merge: ";
  list3.merge_2sorted_lists(list4);
  list3.print();
}
