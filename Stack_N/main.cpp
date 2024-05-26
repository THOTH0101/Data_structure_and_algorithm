#include <bits/stdc++.h>

#include "Stack.h"
using namespace std;

int main() {
  Stack stk(3);
  stk.push(10);
  stk.push(20);
  stk.push(30);

  if (!stk.isFull())
    stk.push(50);
  else
    cout << "Full Stack\n";
  stk.display();  // 30 20 10
  int result;
  stk.peek(result);
  cout << result << "\n";  // 30

  while (!stk.isEmpty()) {
    stk.pop(result);
    cout << result << " ";
  }  // 30 20 10
  cout << endl;

  return 0;
}
