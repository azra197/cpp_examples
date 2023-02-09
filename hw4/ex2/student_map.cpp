#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

struct student {
  int index;
  std::string name;
  std::string lastname;
  double av_grade;
};

std::map<int, student> map_of_students;

void EnterStudent() {
  int student_index;
  std::string student_name;
  std::string student_lastname;
  double student_average_grade;
  std::cout << "Enter index, name, lastname and average grade of the student: "
            << std::endl;
  std::cin >> student_index;
  std::cin >> student_name;
  std::cin >> student_lastname;
  std::cin >> student_average_grade;

  student new_student;
  new_student.index = student_index;
  new_student.name = student_name;
  new_student.lastname = student_lastname;
  new_student.av_grade = student_average_grade;

  auto it = map_of_students.find(new_student.index);
  if (it == map_of_students.end()) {
    map_of_students.insert(std::make_pair(student_index, new_student));
    std::cout << "You have successfully entered a new student!\n" << std::endl;
  } else {
    std::cout << "Student already exist!" << std::endl;
  }
}

void EraseStudent() {
  int student_index;
  std::cout << "Please enter index of the student you want to delete."
            << std::endl;

  std::cin >> student_index;
  student erase_student;
  auto it = map_of_students.find(student_index);
  if (it == map_of_students.end()) {
    std::cout << "Student doesn't exist. You can't erase it!" << std::endl;
  }

  else {
    int erase_index;
    erase_index = erase_student.index;
    std::cout << " Name, lastname, index and average grade of the "
                 "student you want to erase: "
              << std::endl;
    std::cout << "\t 1.Name:" << it->second.name << std::endl;
    std::cout << "\t 2.Lastname:" << it->second.lastname << std::endl;
    std::cout << "\t 3.Index: " << it->second.index << std::endl;
    std::cout << "\t 4.Average grade: " << it->second.av_grade << "\n"
              << std::endl;
    std::cout << "\t Are you sure you want to erase this student?" << std::endl;
    std::cout << "\t If YES press 1" << std::endl;
    std::cout << "\t If NO press 0" << std::endl;
    int erase_option;
    std::cin >> erase_option;
    if (erase_option == 0) {
      std::cout << "You didn't erase the student\n" << std::endl;
    } else {
      map_of_students.erase(student_index);
      std::cout << "You erased the student with index " << student_index << "\n"
                << std::endl;
    }
  }
}

void DisplayStudents() {
  std::cout << "All students:" << std::endl;
  for (auto it = map_of_students.begin(); it != map_of_students.end(); ++it) {
    std::cout << it->second.index << " " << it->second.name << " "
              << it->second.lastname << " " << it->second.av_grade << std::endl;
  }
  std::cout << "\n" << std::endl;
}

void DisplayIndividualStudent() {
  std::cout << "Please enter the index of the specific student:" << std::endl;
  int student_index;
  std::cin >> student_index;
  auto it = map_of_students.find(student_index);
  if (it == map_of_students.end()) {
    std::cout << "Student with this index doesn't exist!\n" << std::endl;
  } else {
    std::cout << "\nIndex: " << it->second.index << std::endl;
    std::cout << "Name: " << it->second.name << std::endl;
    std::cout << "Lastname: " << it->second.lastname << std::endl;
    std::cout << "Average grade: " << it->second.av_grade << std::endl;
    std::cout << "\n" << std::endl;
  }
}

int main() {
  while (true) {
    std::cout << "\t Please choose one of the options below: " << std::endl;
    std::cout << "\t 1.Enter student" << std::endl;
    std::cout << "\t 2.Erase student" << std::endl;
    std::cout << "\t 3.Display all students" << std::endl;
    std::cout << "\t 4.Display individual student" << std::endl;
    std::cout << "\t 5.Exit" << std::endl;

    int option;
    std::cin >> option;

    while (option < 1 || option > 5) {
      std::cout << "Invalid input. Try again." << std::endl;
      std::cout << "Your new choice: ";
      std::cin >> option;
    }

    switch (option) {
      case 1:
        EnterStudent();
        break;

      case 2:
        EraseStudent();
        break;

      case 3:
        DisplayStudents();
        break;

      case 4:
        DisplayIndividualStudent();
        break;

      case 5:
        exit(1);
    }
  }
  return 0;
}
