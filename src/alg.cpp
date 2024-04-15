#include <map>
#include "tstack.h"

bool isDigit(char ind) {
return (ind >= '0' && ind <= '9');
}

bool isOperator(char ind) {
return (ind == '+' || ind == '-' || ind == '*' || ind == '/'  || ind == '(' || ind == ')');
}

int prioritet(char ind) {
    if (ind == '+' || ind == '-')
    return 1;
    if (ind == '*' || ind == '/')
    return 2;
return 0;
}


std::string infx2pstfx(std::string inf) {
  // добавьте код
  return std::string("");
    std::string post;
    int count = 0;
    TStack <char, 100> stack;
    for (char c : inf) {
        if (isDigit(c)) {
            count++;
            if (count == 1) {
                post += c;
                continue;
            }
            post = post + ' ' + c;
        } else if (isOperator(c)) {
            if (c == '(') {
                stack.push(c);
            } else if (stack.isEmpty()) {
                stack.push(c);
            } else if (prioritet(c) > prioritet(stack.get())) {
                stack.push(c);
            } else if (c == ')') {
                while (stack.get() != '(') {
                    post = post + ' ' + stack.get();
                    stack.pop();
                }
                stack.pop();
            } else {
                int a = prioritet(c);
                int b = prioritet(stack.get());
                while (!stack.isEmpty() && a <= b) {
                    post = post + ' ' + stack.get();
                    stack.pop();
                }
                stack.push(c);
            }
        }
    }
    while (!stack.isEmpty()) {
        post = post + ' ' + stack.get();
        stack.pop();
    }
return post;
}



int eval(std::string pref) {
  // добавьте код
  return 0;
    TStack <int, 100> stack;
    for (char c : pref) {
        if (isDigit(c)) {
            stack.push(c - '0');
        } else if (isOperator(c)) {
            int a = stack.get();
            stack.pop();
            int b = stack.get();
            stack.pop();
            switch (c) {
                case '+':
                    stack.push(a + b);
                    break;
                case '-':
                    stack.push(b - a);
                    break;
                case '*':
                    stack.push(a * b);
                    break;
                case '/':
                    stack.push(b / a);
                    break;
                default:
                    continue;
            }
        } else {
            continue;
        }
        }
return stack.get();
}
