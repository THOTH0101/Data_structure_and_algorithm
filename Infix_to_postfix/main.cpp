#include <bits/stdc++.h>

#include <cctype>
#include <exception>

#include "Stack.h"
using namespace std;

// Function declaration
void test();
void test1();
void test2();
string infix_to_postfix(string& infix);
int precedence(char op);

int main() {
  try {
    test();
    test1();
    test2();
  } catch (exception& ex) {
    cout << ex.what() << endl;
  }
  return 0;
}

// Functions implementation
void test() {
  string expression = "a+b*(c^d-e)^(f+G*h)-i";
  string postfix = infix_to_postfix(expression);

  cout << expression << " => " << postfix << endl;
}

void test1() {
  string expression = "5+4^3^2-9";
  string postfix = infix_to_postfix(expression);

  cout << expression << " => " << postfix << endl;
}

void test2() {
  string expression = "1+2^3^4*5-6";
  string postfix = infix_to_postfix(expression);

  cout << expression << " => " << postfix << endl;
}

string infix_to_postfix(string& infix) {
  string to_post = "";

  for (int i = 0; i < 26; i++) {
    to_post += (char)(i + 'a');
    to_post += (char)(i + 'A');

    if (i < 10) to_post += i;
  }

  infix += '-';
  string postfix;
  Stack<char> operators;
  operators.push('#');

  for (int i = 0; i < infix.length(); i++) {
    if (isdigit(infix[i]) || to_post.find(infix[i]) != string::npos)
      postfix += infix[i];
    else if (infix[i] == '(')
      operators.push(infix[i]);
    else if (infix[i] == ')') {
      while (operators.peek() != '(') postfix += operators.pop();
      operators.pop();
    } else {
      while (precedence(operators.peek()) > precedence(infix[i]) ||
             precedence(operators.peek()) == precedence(infix[i]) &&
                 infix[i] != '^')
        postfix += operators.pop();
      operators.push(infix[i]);
    }
  }

  return postfix;
}

int precedence(char op) {
  if (op == '^') return 3;
  if (op == '*' || op == '/') return 2;
  if (op == '-' || op == '+') return 1;
  return 0;
}
