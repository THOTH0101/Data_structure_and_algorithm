#include <bits/stdc++.h>

#include "Last_k_numbers_sum_stream.h"
using namespace std;

int main() {
  Last_k_numbers_sum_stream processor(4);

  int num;
  while (cin >> num) cout << processor.next(num) << "\n";
  return 0;
}
