#include <iostream>
#include "queue.hpp"

int main() {
  Queue<int> r;
  r.push(1);
  for (int i = 2; i < 5; i++) r.push(i);

  std::cout << "The size: " << r.size() << std::endl;

  while (!r.empty()) {
    std::cout << r.top() << ' ';
    r.pop();
  }

  std::cout << std::endl;
  std::cout << std::endl;

  r.push(1);
  r.push(2);
  std::cout << "New queue: " << r << std::endl;

  Queue<int> r2;
  r2 = std::move(r);

  std::cout << std::endl;
  std::cout << "Assignment Move" << std::endl;
  std::cout << "r2: " << r2 << std::endl;
  std::cout << "r1 :" << r << std::endl;

  Queue<int> r3;
  r3 = r2;
  std::cout << "Assignment Copy" << std::endl;
  std::cout << "r2: " << r2 << std::endl;
  std::cout << "r3 :" << r3 << std::endl;

  
  Queue<int> r4;
  r4.push(5);
  r4.push(6);
  std::cout << r4 << std::endl;

  Queue<int> r5(std::move(r4));
  std::cout << "Move Copy" << std::endl;
  std::cout << "r5: " << r5 << std::endl;
  std::cout << "r4 :" << r4 << std::endl;

  Queue<int> r6(r5);
  std::cout << "Copy" << std::endl;
  std::cout << "r6: " << r6 << std::endl;
  std::cout << "r5 :" << r5 << std::endl;
 
  return 0;
}
