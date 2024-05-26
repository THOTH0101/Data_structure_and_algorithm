#include <bits/stdc++.h>

#include <exception>

#include "Stack.h"
using namespace std;

void test();

int main() {
  try {
    test();
  } catch (exception& ex) {
    cout << ex.what() << endl;
  }

  return 0;
}

void test() {
  Stack stk(10);

  stk.push(2, 5);
  stk.push(2, 6);
  cout << stk.pop(2) << endl;
  stk.push(2, 7);
  stk.push(2, 9);

  stk.push(1, 4);
  cout << stk.peek(1) << endl;
  cout << stk.peek(2) << endl;
  stk.push(1, 6);
  stk.push(1, 8);
  stk.push(2, 3);
  stk.display();
}
