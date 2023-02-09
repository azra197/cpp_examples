#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
  std::ifstream text;
  std::map<std::string, std::vector<int>> words;
  std::string word;
  std::map<std::string, std::vector<int>>::iterator it;
  text.open("story.txt");

  int temp = 0;
  if (text.is_open()) {
    while (text >> word) {
      words[word].push_back(temp);
      ++temp;
    }
  }
  for (it = words.begin(); it != words.end(); it++) {
    std::cout << "Rijec je " << (*it).first
              << " i nalazi se na sljedecim pozicijama:" << std::endl;
    for (auto i = ((*it).second.begin()); i != ((*it).second.end()); ++i) {
      std::cout << *i << "\t";
    }
    std::cout << std::endl;
  }
  text.close();
  return 0;
}
