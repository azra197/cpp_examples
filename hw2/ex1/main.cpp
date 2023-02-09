#include <iostream>
#include "stack_array.hpp"
#include "stack_list.hpp"

int main() {
  Stack_Array<int> s1;

  Stack_List<int> s2;

  std::cout << "Stack_Array" << std::endl;

  for (int i = 0; i < 5; ++i) s1.push(i);

  std::cout << s1.top() << std::endl;  // 4
  s1.pop();
  std::cout << s1.top() << std::endl;  // 3

  std::cout << "The size of the Array stack: " << s1.size() << std::endl;

  while (!s1.empty()) {
    std::cout << s1.top() << ' ';
    s1.pop();
  }
  std::cout << std::endl;

  Stack_Array<int> ss1;
  ss1.push(1);
  ss1.push(2);
  std::cout << ss1 << std::endl;
  Stack_Array<int> s3 = std::move(ss1);
  std::cout << "Assignment Move" << std::endl;
  std::cout << "s3: " << s3 << std::endl;
  std::cout << "ss1 :" << ss1 << std::endl;

  Stack_Array<int> s4;
  s4 = s3;
  std::cout << "Assignment Copy" << std::endl;
  std::cout << "s3: " << s3 << std::endl;
  std::cout << "s4 :" << s4 << std::endl;

  Stack_Array<int> s5;
  s5.push(5);
  s5.push(6);
  std::cout << s5 << std::endl;
  Stack_Array<int> s6(std::move(s5));
  std::cout << "Move Copy" << std::endl;
  std::cout << "s6: " << s6 << std::endl;
  std::cout << "s5 :" << s5 << std::endl;

  Stack_Array<int> s7(s6);
  std::cout << "Copy" << std::endl;
  std::cout << "s7: " << s7 << std::endl;
  std::cout << "s6 :" << s6 << std::endl;

  for (int i = 0; i < 5; ++i) s1.push(i);
  for (int i = 5; i < 10; ++i) ss1.push(i);

  std::cout << "Stacks are the same?: " << s1.operator==(ss1) << std::endl;
  std::cout << "Stacks are different?: " << s1.operator!=(ss1) << std::endl;

  auto sum1 = s1 + ss1;
  std::cout << "Sum of two stacks(array): " << sum1 << std::endl;

  std::cout << std::endl;
  std::cout << "Stack_List" << std::endl;
  for (int i = 0; i < 10; ++i) s2.push(i);
  std::cout << s2.top() << std::endl;  // 9
  s2.pop();
 std::cout << "The size of the List stack: " << s2.size() << std::endl;


  while (!s2.empty()) {
    std::cout << s2.top() << ' ';
    s2.pop();
  }
  std::cout << std::endl;

  Stack_List<int> ss2;
  ss2.push(1);
  ss2.push(2);
  std::cout << ss2 << std::endl;
  Stack_List<int> s_list2 = std::move(ss2);
  std::cout << "Assignment Move" << std::endl;
  std::cout << "s_list2: " << s_list2 << std::endl;
  std::cout << "ss2 :" << ss2 << std::endl;

  Stack_List<int> s_list3;
  s_list3 = s_list2;
  std::cout << "Assignment Copy" << std::endl;
  std::cout << "s_list2: " << s_list2 << std::endl;
  std::cout << "s_list3 :" << s_list3 << std::endl;

  Stack_List<int> s_list4;
  s_list4.push(5);
  s_list4.push(6);
  std::cout << s_list4 << std::endl;
  Stack_List<int> s_list5(std::move(s_list4));
  std::cout << "Move Copy" << std::endl;
  std::cout << "s_list5: " << s_list5 << std::endl;
  std::cout << "s_list4 :" << s_list4 << std::endl;

  Stack_List<int> s_list6(s_list5);
  std::cout << "Copy" << std::endl;
  std::cout << "s_list6: " << s_list6 << std::endl;
  std::cout << "s_list5 :" << s_list5 << std::endl;

  for (int i = 0; i < 5; ++i) s2.push(i);
  for (int i = 0; i < 5; ++i) ss2.push(i);

   std::cout << "Stacks are the same?: " << operator==(s2, ss2) << std::endl;
  std::cout << "Stacks are different?: " << operator!=(s2, ss2) << std::endl;

  auto sum2 = s2 + ss2;
  std::cout << "Sum of two stacks(list): " << sum2 << std::endl;
}
