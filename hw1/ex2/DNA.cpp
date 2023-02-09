#include <iostream>
#include <string>

int main() {
  int choice, position, length;
  std::string DNA, temp;
  std::cout
      << "Welcome to DNA storage. Please enter one of the following options:"
      << std::endl
      << "\n\t1. Print\n\t2. Insert <pos> <lanac>\n\t3. Remove <pos> <len>"
      << std::endl;
  while (1) {
    std::cout << "\nYour choice: ";
    std::cin >> choice;

    switch (choice) {
      case 1:
        if(DNA.length()==0) {
          std::cout<< std::endl<< "DNA: " << std::endl;
        } else {
        std::cout<< "DNA: " << DNA << std::endl;}
        break;
      case 2:
        std::cout << "Position: ";
        std::cin >> position;
        std::cout << "Value: ";
        std::cin >> temp;

        DNA.insert(position, temp);
        break;
      case 3:
        std::cout << "Position: ";
        std::cin >> position;
        std::cout << "Length: ";
        std::cin >> length;
        DNA.erase(position, length);
        break;
      default:
        std::cout << "KRAJ";
        return 0;
    }

    std::cin.ignore(1000, '\n');
  }
}
