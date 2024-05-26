#include <bits/stdc++.h>

#include "ArrayLinkedList.h"
using namespace std;

void test();

int main() {
  test();
  return 0;
}

void test() {
  ArrayLinkedList array(10);
  array.set_value(50, 5);
  array.set_value(20, 2);
  array.set_value(70, 7);
  array.set_value(40, 4);

  array.print_array();
  array.print_array_nonzero();

  ArrayLinkedList array2(10);
  array2.set_value(1, 4);
  array2.set_value(3, 7);
  array2.set_value(4, 6);

  array.add(array2);
  array.print_array();
}
