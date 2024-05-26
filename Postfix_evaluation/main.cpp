#include <bits/stdc++.h>

#include <cctype>
#include <cmath>
#include <exception>
#include <iostream>

#include "Stack.h"
using namespace std;

// function definnition
void test();
void test1();
double evaluate_postfix(string postfix);
double evaluate_expression(double op1, double op2, char op);

int main() {
  try {
    test();
    test1();
  } catch (exception& ex) {
    cout << ex.what() << endl;
  }

  return 0;
}

// function implementation
void test() {
  string exp = "135*+72/-";

  cout << exp << " => " << evaluate_postfix(exp) << endl;
}

void test1() {
  string exp = "432^^";

  cout << exp << " => " << evaluate_postfix(exp) << endl;
}

double evaluate_postfix(string postfix) {
  Stack<double> operands;

  for (int i = 0; i < postfix.length(); i++) {
    if (isdigit(postfix[i]))
      operands.push(postfix[i] - '0');
    else {
      double op1, op2, result;
      op1 = operands.pop();
      op2 = operands.pop();
      result = evaluate_expression(op1, op2, postfix[i]);

      operands.push(result);
    }
  }
  return operands.pop();
}

double evaluate_expression(double op1, double op2, char op) {
  double result;

  if (op == '^')
    result = pow(op2, op1);
  else if (op == '/')
    result = op2 / op1;
  else if (op == '*')
    result = op2 * op1;
  else if (op == '+')
    result = op2 + op1;
  else if (op == '-')
    result = op2 - op1;

  return result;
}
