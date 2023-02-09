#include <iostream>
#include "list.hpp"

int main() {
  List<int> moja_lista;
 
  moja_lista.push_back(3);
  moja_lista.push_back(4);
  moja_lista.push_front(std::move(2));
  moja_lista.push_front(1);
  moja_lista.push_front(std::move(0));
  moja_lista.push_back(5);

  auto moja_lista2 = moja_lista;

  auto moja_lista3 = std::move(moja_lista);

  moja_lista3.pop_front();
  moja_lista3.pop_back();

  List<int>::iterator iter = moja_lista3.begin();
  while (iter != moja_lista3.end()) {
    std::cout << *iter++ << " ";
  }
  std::cout << *iter;
  std::cout << std::endl;

  List<std::string> list_of_words;
  list_of_words.push_back("Hello ");
  list_of_words.push_back("Welcome ");
  list_of_words.push_back("everyone ");

  auto pos = list_of_words.begin();
  list_of_words.insert(pos, "My friend ");
  list_of_words.insert(list_of_words.begin(), "Hi ");
  list_of_words.remove(++list_of_words.begin());
  List<std::string>::iterator it_string = list_of_words.begin();
  while (it_string != list_of_words.end()) {
    std::cout << *it_string << " ";
    ++it_string;
  }
  std::cout << *it_string;
  std::cout << "" << std::endl;
  return 0;
}
