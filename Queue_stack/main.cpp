#include <bits/stdc++.h>

#include <exception>

#include "Stack.h"
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
  Stack stk(3);
  stk.push(10);
  stk.push(20);
  stk.push(30);

  while (!stk.isEmpty()) {
    cout << stk.peek() << " ";
    stk.pop();
  }
  cout << endl;
}
