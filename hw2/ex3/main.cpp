#include <iostream>
#include <string>
#include "postfix_calc.hpp"

int main() {
  PostfixCalc<int> result;
  std::string exp;
  std::cout << "Calculator \n" << std::endl;
  do {
    std::cout << "Enter expression or exit to finish: \n";
    std::getline(std::cin, exp);
    if (exp == "exit") break;
    int res = result.check(exp);
    std::cout << " = " << res << "\n";
  } while (true);
  return 0;
}
