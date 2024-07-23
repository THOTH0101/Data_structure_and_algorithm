#ifndef KTH_SMALLEST_NUMBER
#define KTH_SMALLEST_NUMBER

#include <bits/stdc++.h>

#include "MaxHeap.h"
using namespace std;

class Kth_smallest_number {
 private:
  int k;
  MaxHeap q;

 public:
  Kth_smallest_number(int k) : k(k) {}

  int next(int new_num) {
    if (q.length() < k)
      q.push(new_num);
    else if (new_num < q.top()) {
      q.pop();
      q.push(new_num);
    }
    return q.top();
  }
};

#endif  // !KTH_SMALLEST_NUMBER
