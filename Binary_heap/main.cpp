#include <bits/stdc++.h>

#include <exception>

#include "MaxHeap.h"
#include "MinHeap.h"
using namespace std;

void test();
void test1();

int main() {
  try {
    test();
    test1();
  } catch (exception& ex) {
    cout << ex.what() << endl;
  }
  return 0;
}

void test() {
  cout << "----- start test -----" << endl;
  vector<int> v{2, 17, 22, 10, 8, 37, 14, 19, 7, 6, 5, 12, 25, 30};
  MinHeap heap(v);

  cout << "print than less: ";
  heap.print_less_than(10);

  cout << "\nis heap: ";
  int arr[]{2, 5, 12, 7, 6, 22, 14, 19, 10, 17, 8, 37, 25, 30};
  cout << boolalpha << heap.is_heap_array(arr, 14) << "\n";  // 1

  cout << "is heap: ";
  swap(arr[0], arr[5]);
  cout << boolalpha << heap.is_heap_array(arr, 14) << "\n";  // 0

  cout << "---- sort array ---" << endl;
  const int SZ = 14;
  int arr1[SZ]{2, 17, 22, 10, 8, 37, 14, 19, 7, 6, 5, 12, 25, 30};

  heap.heap_sort(arr1, SZ);

  for (int i = 0; i < SZ; ++i) cout << arr1[i] << " ";
  cout << "\n";
  cout << "\n----- end test -----" << endl << endl;
}

void test1() {
  cout << "----- start test -----" << endl;
  MaxHeap heap;

  vector<int> v{2, 17, 22, 10, 8, 37, 14, 19, 7, 6, 5, 12, 25, 30};

  for (int i = 0; i < (int)v.size(); ++i) heap.push(v[i]);

  while (!heap.isempty()) {
    cout << heap.top() << " ";
    heap.pop();
  }
  cout << "\n----- end test -----" << endl << endl;
}
