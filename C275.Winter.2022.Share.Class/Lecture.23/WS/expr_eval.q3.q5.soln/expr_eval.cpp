/*
  Implementation of an algorithm that evaluates an infix expression,
   eg. 5.0 * ( 4.0 + 17.1 - 2.0 * 5.3 ) + 1.1

  Uses doubles for the values and supports the following:
   - brackets ( )
   - binary opers *, /, -, +

  Reads the input from standard in, assumes there is at least one space between
  every value/oper/bracket (i.e. all "tokens" have at least one space
  between them). Use ctrl-d after the last token if you are typing them in.

  Does not check that every "token" is valid (i.e. a value, bracket, or
  supported operator) and that the expression is always valid, but it
  does check for some errors (eg. imbalanced parenthesis and
  some misplaced operators).

  Runs in O(n) time where n is the number of tokens.

  Uses the Shunting-Yard algorithm to first convert the expression to
  postfix notation:

   eg. 5.0 4.0 17.1 2.0 5.3 * - + * 1.1 +

  And then it evaluates the postfix expression.
*/

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <cmath> // for pow()

using namespace std;

// Evaluate the top values in the value stack at the given operator.
// Pops the values and then pushes the result.
// Currently only supports binary operators (so we always pop 2 from the stack).
void eval_top(stack<double>& value_stack, const string& op) {
  double vals[2], res;

  // figure out how many values we need to pop
  int num_vals;
  if (op == "sqrt" || op == "log") {
    num_vals = 1;
  }
  else {
    num_vals = 2;
  }

  // the values pop off the stack in "right to left" order
  for (int i = num_vals-1; i >= 0; --i) {
    if (value_stack.size() == 0) {
      cerr << "Malformed expression, stack empty during operator evaluation." << endl;
      exit(1);
    }
    vals[i] = value_stack.top();
    value_stack.pop();
  }

  if (op == "+") {
    res = vals[0] + vals[1];
  }
  else if (op == "-") {
    res = vals[0] - vals[1];
  }
  else if (op == "*") {
    res = vals[0] * vals[1];
  }
  else if (op == "/") {
    res = vals[0] / vals[1];
  }
  else if (op == "^") {
    res = pow(vals[0], vals[1]);
  }
  else if (op == "sqrt") {
    res = sqrt(vals[0]);
  }
  else if (op == "log") {
    res = log(vals[0]);
  }
  else {
    // shouldn't get here if the the operators in the operator set
    // from postfix_eval are the same as the cases above
    cerr << "Unknown operator..." << endl
         << "How did we get here?" << endl;
    exit(1);
  }

  value_stack.push(res);
}

// Evaluates a postfix expression.
// Assumes all entries are -,+,*,/ or the string representation of a double
// (i.e. using stod() will convert it to a double successfully).
double postfix_eval(const vector<string>& postfix) {
  // functions are thought of as unary operators now
  unordered_set<string> operators = {"-", "+", "*", "/", "^", "sqrt", "log"};

  if (postfix.size() == 0) {
    cerr << "Empty expression." << endl;
    exit(1);
  }

  stack<double> value_stack;

  // Scan through the tokens.
  for (const string& tok : postfix) {
    if (operators.find(tok) != operators.end()) {
      // Apply the operator to the top of the value stack
      eval_top(value_stack, tok);
    }
    else {
      // An example of C++ exception handling, for your curiousity.
      try {
        value_stack.push(stod(tok));
      }
      catch (...) {
        cerr << "Cannot convert token \"" << tok << "\" to a double using stod()" << endl;
        cerr << "Remember: tokens must be separated by a space." << endl;
        exit(1);
      }
    }
  }

  if (value_stack.size() > 1) {
    cerr << "Malformed expression, too many values in the final stack." << endl;
    exit(1);
  }

  return value_stack.top();
}

// Converts an infix expression to postfix using the Shunting-Yard algorithm.
vector<string> shunting_yard(const vector<string>& infix) {
  unordered_map<string, int> prec = {
    {"^", 3}, {"*", 2}, {"/", 2}, {"+", 1}, {"-", 1}
  };

  unordered_set<string> functions = { "sqrt", "log" };

  // the postfix expression we are constructing
  vector<string> postfix;

  // the oper stack from the slides
  stack<string> oper;

  // scan through the tokens one at a time
  for (const string& tok : infix) {
    if (prec.find(tok) != prec.end()) {
      // CASE: if the token is an operator

      while (oper.size() > 0 && oper.top() != "(" && prec[oper.top()] >= prec[tok]) {
        postfix.push_back(oper.top());
        oper.pop();
      }
      oper.push(tok);
    }
    else if (tok == "(" or functions.find(tok) != functions.end()) {
      // CASE: if the token is an open bracket or a function name

      oper.push(tok);
    }
    else if (tok == ")") {
      // CASE: if the token is a closing bracket

      while (oper.size() > 0 && oper.top() != "(") {
        postfix.push_back(oper.top());
        oper.pop();
      }
      if (oper.size() == 0) {
        cerr << "Error, missing opening bracket." << endl;
        exit(1);
      }
      oper.pop(); // pop the opening bracket

      // if the open bracket was preceded by a function name, move that to
      // the stack as well
      if (oper.size() > 0 && functions.find(oper.top()) != functions.end()) {
        postfix.push_back(oper.top());
        oper.pop();
      }
    }
    else {
      // CASE: a value (everything else is assumed to be a value)
      // We won't convert the string to the value yet, that will happen
      // in postfix_eval

      postfix.push_back(tok);
    }
  }

  // Done scanning, so pop operators (move to postfix) until
  // until they are all taken care of.
  while (oper.size() > 0) {
    if (oper.top() == "(") {
      cerr << "Error, missing closing bracket." << endl;
      exit(1);
    }

    postfix.push_back(oper.top());
    oper.pop();
  }

  return postfix;
}

// Prints the sequence of tokens represented by expr.
// It is handy to print a label first.
void print_expression(const string& label, const vector<string>& expr) {
    cout << label;
    for (const auto& s : expr) {
      cout << ' ' << s;
    }
    cout << endl;
}

int main() {
  vector<string> infix;

  // read all tokens from the input
  // stops when cin >> s fails (i.e. no more strings in the input)
  for (string s; cin >> s; infix.push_back(s));

  // echo it back to the user
  print_expression("Infix:  ", infix);

  // convert to postfix
  vector<string> postfix = shunting_yard(infix);

  // show the postfix expression to the user
  print_expression("Postfix:", postfix);

  // evaluate the postfix expression and print the value
  double val = postfix_eval(postfix);
  cout << "Value:   " << val << endl;

  return 0;
}
