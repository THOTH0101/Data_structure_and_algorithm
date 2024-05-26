#include <bits/stdc++.h>

#include <algorithm>
#include <cctype>
#include <exception>

#include "Stack.h"

using namespace std;

// function definition
void test();
void test1();
void test2();
void test3();
string infix_to_prefix(string& infix);
int precedence(char op);

int main() {
  try {
    test();
    test1();
    test2();
    test3();
  } catch (exception& ex) {
    cout << ex.what() << endl;
  }
}

// function implementation
void test() {
  string exp = "1+3*5-8/2";

  cout << exp << " => " << infix_to_prefix(exp) << endl;
}

void test1() {
  string exp = "4^3^2";

  cout << exp << " => " << infix_to_prefix(exp) << endl;
}

void test2() {
  string exp = "2*3+4";

  cout << exp << " => " << infix_to_prefix(exp) << endl;
}

void test3() {
  string exp = "a+b-c";

  cout << exp << " => " << infix_to_prefix(exp) << endl;
}

string infix_to_prefix(string& infix) {
  string to_post = "";

  for (int i = 0; i < 26; i++) {
    to_post += (char)(i + 'a');
    to_post += (char)(i + 'A');

    if (i < 10) to_post += i;
  }

  infix.insert(0, "#");
  string prefix;
  Stack<char> operators;
  operators.push('#');

  for (int i = infix.length() - 1; i >= 0; i--) {
    if (isdigit(infix[i]) || to_post.find(infix[i]) != string::npos)
      prefix += infix[i];
    else if (operators.peek() == '^' && infix[i] == '^')
      prefix += infix[i];
    else if (infix[i] == '(')
      operators.push(infix[i]);
    else if (infix[i] == ')') {
      while (operators.peek() != '(') prefix += operators.pop();
      operators.pop();
    } else {
      while (precedence(operators.peek()) > precedence(infix[i]))
        prefix += operators.pop();
      operators.push(infix[i]);
    }
  }

  reverse(prefix.begin(), prefix.end());
  return prefix;
}

int precedence(char op) {
  if (op == '^') return 3;
  if (op == '/' || op == '*') return 2;
  if (op == '+' || op == '-') return 1;
  return 0;
}
