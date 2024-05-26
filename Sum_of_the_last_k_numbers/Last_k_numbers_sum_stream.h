#ifndef LAST_K_NUMBERS_SUM_STREAM
#define LAST_K_NUMBERS_SUM_STREAM

#include <algorithm>

#include "Queue.h"
using namespace std;

class Last_k_numbers_sum_stream : public Queue {
 private:
  int count;

 public:
  Last_k_numbers_sum_stream(int k) : Queue(k) { count = k; }

  int next(int new_num) {
    if (isFull()) dequeue();
    enqueue(new_num);

    return sum_total();
  }
};

#endif
