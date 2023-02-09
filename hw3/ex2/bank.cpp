#include <iostream>
#include "queue.hpp"

struct Transaction {
  double value;
  std::string date;
  std::string time;
  char opt;
};

Queue<Transaction> myTransactions(5);

double ballance = 0;

void NewTransaction() {
  Transaction trans;
  std::cout << "\nInput value for transaction: ";
  std::cin >> trans.value;
  std::cout << "Input date: ";
  std::cin >> trans.date;
  std::cout << "Input time: ";
  std::cin >> trans.time;
  std::cout << "Your choice (+ or -): ";
  std::cin >> trans.opt;
  myTransactions.push(trans);
}

void ApplyTransaction() {
  if (myTransactions.size() != 0) {
    Transaction temp = myTransactions.pop();
    if (temp.opt == '+') {
      ballance += temp.value;
    } else if (temp.opt == '-') {
      if (ballance >= temp.value) {
        ballance -= temp.value;
      } else
        std::cout << "\nDon't enough money on Your account. " << std::endl;
    }
  } else {
    std::cout << "\nList of transaction is empty. " << std::endl;
  }
}

void PendingTransaction() {
  if (myTransactions.size() != 0) {
    Transaction temp = myTransactions.top();
    std::cout << "\nPending transaction:" << std::endl;
    std::cout << "\tValue:\t " << temp.value << std::endl;
    std::cout << "\tDate:\t " << temp.date << std::endl;
    std::cout << "\tTime:\t " << temp.time << std::endl;
    std::cout << "\tYour choice (+) or (-): " << temp.opt << std::endl;
  } else
    std::cout << "\nList of transaction is empty. " << std::endl;
}

void DiscardTransaction() {
  if (myTransactions.size() != 0) {
    myTransactions.pop();
  } else
    std::cout << "\nList of transaction is already empty. " << std::endl;
}

int main() {
  while (true) {
    std::cout << "\n***************************************" << std::endl;
    std::cout << "Action:" << std::endl;
    std::cout << "\t1. New transaction" << std::endl;
    std::cout << "\t2. Apply transaction" << std::endl;
    std::cout << "\t3. Pending transaction" << std::endl;
    std::cout << "\t4. Discard pending transaction" << std::endl;
    std::cout << "\t5. Ballance" << std::endl;
    std::cout << "\t6. Exit" << std::endl;
    std::cout << "Your choice? ";
    size_t a;
    std::cin >> a;

    while (a < 1 || a > 6) {
      std::cout << "Invalid input. Try again." << std::endl;
      std::cout << "Your new choice: ";
      std::cin >> a;
    }
    switch (a) {
      case 1:
        NewTransaction();
        break;
      case 2:
        ApplyTransaction();
        break;
      case 3:
        PendingTransaction();
        break;
      case 4:
        DiscardTransaction();
        break;
      case 5:
        std::cout << "\nCurrent state of Your account is: " << ballance
                  << std::endl;
        break;
      case 6:
        exit(1);
    }
  }
  return 0;
}
