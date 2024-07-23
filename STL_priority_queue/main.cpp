#include <bits/stdc++.h>

#include "Kth_smallest_number.h"
#include "PriorityQueue.h"
using namespace std;

void kthSmallestNumberTest();
void priorityQueueTest();

int main() {
  // kthSmallestNumberTest();
  priorityQueueTest();
  return 0;
}

void kthSmallestNumberTest() {
  Kth_smallest_number processor(4);

  int num;
  while (cin >> num) cout << processor.next(num) << "\n";
}

void priorityQueueTest() {
  PriorityQueue tasks;

  tasks.enqueue(1131, 1);
  tasks.enqueue(3111, 3);
  tasks.enqueue(2211, 2);
  tasks.enqueue(3161, 3);
  tasks.enqueue(7761, 7);

  cout << tasks.dequeue() << "\n";
  cout << tasks.dequeue() << "\n";

  tasks.enqueue(1535, 1);
  tasks.enqueue(2815, 2);
  tasks.enqueue(3845, 3);
  tasks.enqueue(3145, 3);

  while (!tasks.isempty()) cout << tasks.dequeue() << " ";
  cout << endl;
}
