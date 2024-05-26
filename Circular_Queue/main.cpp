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
  qu.display();

  for (int i = 1; i <= 6; ++i) {
    qu.enqueue(i);
    qu.display();
  }

  for (int i = 1; i <= 6; ++i) {
    qu.dequeue();
    // qu.display();
  }

  for (int i = 1; i <= 6; ++i) {
    qu.enqueue(i);
    qu.display();
  }

  qu.dequeue();
  qu.enqueue(7);
  qu.display();

  qu.dequeue();
  qu.dequeue();
  qu.enqueue(8);
  qu.display();
  qu.enqueue(9);
  qu.display();

  for (int i = 1; i <= 6; ++i) {
    qu.dequeue();
    qu.display();
  }
}
