#pragma once
#include <iostream>
#include <string>
#include "stack_array.hpp"

template <typename Type>
class PostfixCalc {
  public:
  bool check_operation(char symbol) {
    if (symbol == '+' or '-' or '*' or '/') {
      return true;
    } else
      return false;
  }

  bool check_number(char number) {
    if (number >= '0' && number <= '9') {
      return true;
    } else
      return false;
  }

  int basic_op(int no2, int no1, char operation) {
    if (operation == '+')
      return no1 + no2;
    else if (operation == '-')
      return no1 - no2;
    else if (operation == '*')
      return no1 * no2;
    else if (operation == '/')
      return no1 / no2;
    else {
      return 0;
    }
  }

  int check(std::string exer) {
    Stack_Array<int> stack;
    for (int i = 0; i < exer.length(); i++) {
      if (exer.at(i) == ' ') {
        continue;
      } else if (check_number(exer.at(i))) {
        int num = 0;
        while (check_number(exer.at(i))) {
          num = num * 10 + exer.at(i) - '0';
          i++;
        }
        i--;
        stack.push(num);
      }

      else if (check_operation(exer.at(i))) {
        int no2 = stack.top();
        stack.pop();
        int no1 = stack.top();
        stack.pop();
        int result = basic_op(no2, no1, exer.at(i));
        stack.push(result);
      }
    }
    return stack.top();
  }

  friend std::ostream& operator<<(std::ostream& out,
                                  const PostfixCalc<Type>& stack) {
    for (int i = 0; i < stack.size_; ++i) {
      out << stack.data_[i] << " ";
    }
    return out;
  }

  private:
  size_t size_;
  Type* data_;
};
