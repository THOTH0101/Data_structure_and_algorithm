#include <bits/stdc++.h>

#include <exception>

#include "Queue.h"
using namespace std;

// function definition
void test();

int main() {
  try {
    test();
  } catch (exception& ex) {
    cout << ex.what() << endl;
  }
}

// function implementation
void test() {
  Queue qu(6);

  for (int i = 1; i <= 3; i++) qu.enqueue(i);

  cout << qu.dequeue() << " ";

  for (int i = 4; i <= 5; i++) qu.enqueue(i);

  while (!qu.isEmpty()) cout << qu.dequeue() << " ";  // 1 2 3 4 5
  cout << endl;
}
