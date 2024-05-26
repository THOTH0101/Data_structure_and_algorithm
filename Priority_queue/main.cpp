#include <bits/stdc++.h>

#include <exception>

#include "PriorityQueue.h"
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
  PriorityQueue tasks(8);

  tasks.enqueue(1131, 1);
  tasks.enqueue(3111, 3);
  tasks.enqueue(2211, 2);
  tasks.enqueue(3161, 3);

  cout << tasks.dequeue() << "\n";
  cout << tasks.dequeue() << "\n";

  tasks.enqueue(1535, 1);
  tasks.enqueue(2815, 2);
  tasks.enqueue(3845, 3);
  tasks.enqueue(3145, 3);

  while (!tasks.isEmpty()) cout << tasks.dequeue() << " ";
  cout << endl;
}
