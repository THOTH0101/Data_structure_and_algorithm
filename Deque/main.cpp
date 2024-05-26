#include <bits/stdc++.h>

#include <exception>

#include "Deque.h"
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
  Deque dp(6);

  dp.enqueue_front(3);
  dp.enqueue_front(2);
  dp.enqueue_end(4);
  dp.enqueue_front(1);
  dp.display();  // 1234

  cout << dp.dequeue_end() << "\n";  // 4
  dp.display();

  cout << dp.dequeue_front() << "\n";  // 1
  dp.display();
  cout << dp.dequeue_end() << "\n";    // 3
  cout << dp.dequeue_front() << "\n";  // 2
  dp.enqueue_end(7);
  dp.display();  // 7
}
