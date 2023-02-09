#include <iostream>
#include <vector>
#include "stack_array.hpp"

std::vector<int> greater_element(std::vector<int>& numbers) {
  int n = numbers.size();
  std::vector<int> vec_result(n, -1);
  Stack_Array<int> stack;
  for (int i = n - 1; i >= 0; --i) stack.push(i);
  for (int i = n - 1; i >= 0; --i) {
    while (stack.empty() == false && numbers.at(stack.top()) <= numbers.at(i))
      stack.pop();
    if (stack.empty()==false) vec_result.at(i) = numbers.at(stack.top());
    stack.push(i);
  }
  return vec_result;
}

int main() {
  // std::vector<int> numbers({3, 2, 4, 25, 11});

  std::vector<int> numbers;
  int input;
  std::cout << "Enter your numbers and 0 to quit: " << std::endl;
  while (std::cin >> input && input != 0) {
    numbers.push_back(input);
  }

  std::cout << "The numbers in the vector are: " << std::endl;
  for (int i = 0; i < numbers.size(); i++)
    std::cout << numbers[i] << " " << std::endl;

  std::vector<int> vec;
  int n = sizeof(numbers) / sizeof(numbers[0]);
  std::cout << "\nNext Greater Element:\n";
  vec = greater_element(numbers);
  for (int i = 0; i < n - 1; i++) {
    std::cout << numbers[i] << "  -------------->  " << vec[i] << std::endl;
  }
  return 0;
}

