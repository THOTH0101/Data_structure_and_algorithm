#include <bits/stdc++.h>

#include "Stack.h"
using namespace std;

void asteriod_collision(int array[], int arraySize);
void next_greater(int list[], int listSize);
int score_of_parentheses(string& s);

int main() {
  int list[] = {-2, -1, 1, 3};
  int listSize = 4;

  asteriod_collision(list, listSize);

  Stack stk(7);

  stk.push(2);
  stk.push(1);
  stk.push(5);
  stk.push(7);
  stk.insert_at_bottom(10);

  stk.display();
  cout << endl;

  stk.reverse();
  stk.display();

  string s = "(()((())))";

  cout << "bracket score: " << score_of_parentheses(s) << endl;

  int array[] = {5, 10, 5, 7, 15, 11};

  cout << "\nThe new with next greater: ";
  next_greater(array, 6);

  return 0;
}

void asteriod_collision(int array[], int arraySize) {
  Stack stk(arraySize);

  for (int i = 0; i < arraySize; i++) {
    int astrd = array[i];

    bool is_explode = false;
    while (!stk.isEmpty() && astrd < 0 && 0 < stk.peek()) {
      if (stk.peek() < -astrd) {
        stk.pop();
        continue;
      } else if (stk.peek() == -astrd)
        stk.pop();
      is_explode = true;
      break;
    }

    if (!is_explode) stk.push(array[i]);
  }

  stk.display_reverse();
}

int score_of_parentheses(string& s) {
  int result;
  int len = s.length();
  Stack stk(len);
  stk.push(0);

  for (int i = 0; i < len; i++) {
    char ch = s[i];

    if (ch == '(')
      stk.push(0);
    else {
      int last = stk.pop();

      if (last == 0)
        last = 1;
      else
        last *= 2;

      int parent = stk.pop() + last;
      stk.push(parent);
    }
  }

  return result = stk.peek();
}

void next_greater(int list[], int listSize) {
  Stack pos(listSize);

  for (int i = 0; i < listSize; i++) {
    while (!pos.isEmpty() && list[i] > list[pos.peek()])
      list[pos.pop()] = list[i];
    pos.push(i);
  }

  while (!pos.isEmpty()) list[pos.pop()] = -1;

  for (int i = 0; i < listSize; i++) cout << list[i] << " ";
  cout << endl;
}
