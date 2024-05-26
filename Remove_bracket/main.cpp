#include <bits/stdc++.h>

#include <cctype>
#include <exception>

#include "Stack.h"
using namespace std;

// function definition
void test();
string remove_brackets(string& input);
char sign(char a, char b);

int main() {
  try {
    test();
  } catch (exception& ex) {
    cout << ex.what() << endl;
  }
}

// function implementation
void test() {
  string exp;

  exp = "9-(2+3)";
  cout << exp << " => " << remove_brackets(exp) << endl;

  exp = "9+(2-3)";
  cout << exp << " => " << remove_brackets(exp) << endl;

  exp = "1-(2-3-(4+5))-6-(7-8)";
  cout << exp << " => " << remove_brackets(exp) << endl;

  exp = "1-(2-3-(4+5-(6-7)))";
  cout << exp << " => " << remove_brackets(exp) << endl;
}

char sign(char a, char b) {
  if (a == b) return '+';
  return '-';
}

string remove_brackets(string& input) {
  string output = "";
  Stack<char> stk;
  stk.push('+');

  for (int i = 0; i < input.length(); i++) {
    char ch = input[i];

    if (isdigit(ch))
      output += input[i];
    else if (ch == '+' || ch == '-')
      output += sign(stk.peek(), ch);
    else if (ch == '(' && i) {
      if (input[i - 1] != '(')
        stk.push(sign(stk.peek(), input[i - 1]));
      else
        stk.push(stk.peek());
    } else
      stk.pop();
  }

  return output;
}
