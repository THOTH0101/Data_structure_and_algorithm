#include <iostream>

#include "LinkedList.h"
using namespace std;

int main() {
  LinkedList list;
  LinkedList list2;

  list2.insert_front(0);
  list2.insert_front(-1);
  list2.insert_front(-2);
  list2.insert_front(-3);

  list.insert_end(9);
  list.insert_end(3);
  list.insert_end(5);
  list.insert_end(10);
  list.insert_end(0);
  list.insert_end(15);

  list2.insert_end(9);
  list2.insert_end(3);
  list2.insert_end(5);
  list2.insert_end(10);
  list2.insert_end(15);

  list2.print();
  list.print();

  cout << "\n\nthe 4th node has value: " << list.get_nth(4)->getData() << endl;
  cout << "from the front 0th node has value: "
       << list.get_front_nth(0)->getData() << endl;
  cout << "the value 15 is at index: " << list.search(15) << endl;
  list.print();

  cout << "the value 10 is at index: " << list.improved_search(10) << endl;
  cout << "the value 10 is at index: " << list.improved_search(10) << endl;
  list.print();

  list.insert_front(0);
  list.insert_front(1);
  list.insert_front(2);

  list.print();

  cout << "\n\ndeleting from front!" << endl;

  list.delete_front();
  list2.delete_front();

  list.print();
  list2.print();

  cout << "deleting from back!" << endl;
  list.delete_end();
  list2.delete_end();
  list.print();
  list2.print();

  cout << "Size of list: " << list.get_size() << endl;
  cout << "Size of list2: " << list2.get_size() << endl;

  cout << "is list == list2: " << boolalpha << list.is_same(list2) << endl;

  cout << "deleting 0 from the list" << endl;
  list.delete_node_with_key(0);
  list.delete_node_with_key(0);
  list.print();

  cout << "\n\nList2 before the swap_pairs: ";
  list2.print();
  cout << endl;
  cout << "After calling the swap_pairs: ";
  list2.swap_pairs();
  list2.print();
  cout << endl;

  cout << "Reverse list" << endl;
  list.reverse();
  list.print();
  list2.insert_end(20);

  cout << "List2 before delete_even_position" << endl;
  list2.print();
  cout << endl;
  cout << "List2 after" << endl;
  list2.delete_even_position();
  list2.print();

  cout << "new value in sorted manner" << endl;
  list.insert_sorted(8);
  list.print();
  list.insert_sorted(6);
  list.print();
  list.insert_sorted(-6);
  list.print();
  list.insert_sorted(20);
  list.print();
  list.insert_sorted(0);
  list.print();

  cout << "\n\nList2 before swap: ";
  list2.print();

  cout << "List2 after swap: ";
  list2.swap_head_and_tail();
  list2.print();

  cout << "Left rotate list" << endl;
  cout << "before: ";
  list.print();
  cout << "after: ";
  list.left_rotate(3);
  list.print();

  LinkedList list3;
  list3.insert_end(18);
  list3.insert_end(9);
  list3.insert_end(1);
  list3.insert_end(3);
  list3.insert_end(1);
  list3.insert_end(5);
  list3.insert_end(3);
  list3.insert_end(12);
  list3.insert_end(5);
  list3.insert_end(1);
  cout << endl;
  list3.print();

  cout << "Moving all 1s to the end" << endl;
  list3.move_to_back(1);
  list3.move_to_back(18);
  list3.move_to_back(5);
  list3.print();

  cout << "\nRemoving last ocurrance of 18" << endl;
  list3.remove_last_occurance(1);
  list3.print();

  cout << "\nRemoving duplicate..." << endl;
  list3.remove_duplicate();
  list.remove_duplicate();
  list.print();
  list3.print();

  cout << "The max is " << list3.max() << endl;
  cout << "The max is " << list3.max2() << endl;

  list.arrange_odd_and_even();
  list.print();

  cout << "\n\nInsert alternate" << endl;
  list.print();
  list3.print();
  list.insert_alternate(list3);
  list.print();

  LinkedList list4;
  list4.insert_end(4);
  list4.insert_end(2);
  list4.insert_end(6);
  list4.insert_end(8);

  LinkedList list5;
  list5.insert_end(1);
  list5.insert_end(0);
  list5.insert_end(0);
  list5.insert_end(1);
  list5.insert_end(1);

  cout << "Adding two huge number:\n  ";
  list4.print();
  cout << "+ ";
  list5.print();
  list4.add_num(list5);
  cout << "= ";
  list4.print();

  LinkedList list6;
  list6.insert_end(1);
  list6.insert_sorted(1);
  list6.insert_sorted(3);
  list6.insert_sorted(7);
  list6.insert_sorted(2);
  list6.insert_sorted(2);
  list6.insert_sorted(6);
  list6.insert_sorted(5);
  list6.insert_sorted(3);
  list6.print();
  cout << "removing all repeated" << endl;
  list6.print();
  list6.remove_all_repeated();
  list6.print();

  cout << "\n\nReverse chain" << endl;
  list.print();
  list.reverse_chain(4);
  list.print();

  return 0;
}
