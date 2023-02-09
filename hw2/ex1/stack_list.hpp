#pragma once
#include <iostream>
#include "stack_interface.h"

template <typename Type>
class Stack_List : public stack_interface<Type> {
  public:
  Stack_List() = default;

  Stack_List(const Stack_List& other);

  Stack_List(Stack_List&& other);
  Stack_List& operator=(const Stack_List& other);
  Stack_List& operator=(Stack_List&& other);
  ~Stack_List();

  void clear();
  void push(const Type& val) override;
  void push(Type&& val) override;

  Type& top() override;
  const Type& top() const override;

  void pop() override;

  size_t size() const override { return size_; }

  bool empty() const override { return size_ == 0; }

  template <Type>
  friend bool operator==(const Stack_List<Type>& stack1,
                         const Stack_List<Type>& stack2);
  template <Type>
  friend bool operator!=(const Stack_List<Type>& stack1,
                         const Stack_List<Type>& stack2);

  friend std::ostream& operator<<(std::ostream& out,
                                  const Stack_List<Type>& s) {
    for (auto p = s.front_; p != nullptr; p = p->next) {
      out << p->data << " ";
    }
    return out;
  }

  Stack_List<Type> operator+(const Stack_List<Type>& stack1);

  const Type& at(size_t index) const;

  private:
  struct Node {
    Type data;
    Node* next;
  };

  Node* front_ = nullptr;
  Node* back_ = nullptr;
  size_t size_ = 0;
};

template <typename Type>
Stack_List<Type>::Stack_List(const Stack_List& other) {
  auto temp = other.front_;
  while (temp != nullptr) {
    push(temp->data);
    temp = temp->next;
  }
}

template <typename Type>
Stack_List<Type>::Stack_List(Stack_List&& other)
    : front_(other.front_), back_(other.back_), size_(other.size_) {
  other.front_ = nullptr;
  other.back_ = nullptr;
  other.size_ = 0;
}

template <typename Type>
Stack_List<Type>& Stack_List<Type>::operator=(const Stack_List& other) {
  clear();
  auto temp = other.front_;
  while (temp != nullptr) {
    push(temp->data);
    temp = temp->next;
  }
  return *this;
}

template <typename Type>
Stack_List<Type>& Stack_List<Type>::operator=(Stack_List&& other) {
  clear();
  front_ = other.front_;
  back_ = other.back_;
  size_ = other.size_;

  other.front_ = nullptr;
  other.back_ = nullptr;
  other.size_ = 0;

  return *this;
}

template <typename Type>
Stack_List<Type>::~Stack_List() {
  /* while (front_ != nullptr) {
     auto temp = front_->next;

     delete front_;
     front_ = temp;
   }*/
  clear();
}

template <typename Type>
void Stack_List<Type>::clear() {
  while (front_ != nullptr) {
    auto temp = front_->next;

    delete front_;
    front_ = temp;
  }
  back_ = nullptr;
  size_ = 0;
}

template <typename Type>
void Stack_List<Type>::push(const Type& val) {
  /* if (back_ == nullptr) {
     push(element);
   } else {
     auto temp = new Node{element, nullptr};
     temp->next = front_;
     front_ = temp;
 */
  auto temp = new Node{val, nullptr};
  temp->data = val;
  if (front_ == nullptr) {
    temp->next = nullptr;
  } else {
    temp->next = front_;
  }
  front_ = temp;
  size_++;
}

template <typename Type>
void Stack_List<Type>::push(Type&& val) {
  auto temp = new Node{std::move(val), nullptr};
  temp->data = std::move(val);
  if (front_ == nullptr) {
    temp->next = nullptr;
  } else {
    temp->next = front_;
  }
  front_ = temp;
  size_++;
}

template <typename Type>
Type& Stack_List<Type>::top() {
  if (front_ == nullptr)
    throw std::underflow_error("Empty stack");
  else
    return front_->data;
}

template <typename Type>
const Type& Stack_List<Type>::top() const {
  if (front_ == nullptr)
    throw std::underflow_error("Empty stack");
  else
    return front_->data;
}

template <typename Type>
void Stack_List<Type>::pop() {
  if (empty()) return;

  if (size() == 1) {
    clear();
    return;
  }

  auto temp = front_;
  front_ = front_->next;
  size_--;
  delete temp;
}

template <class Type>
bool operator!=(const Type& stack1, const Type& stack2) {
  auto element1 = 0, element2 = 0;

  if (stack1.empty() && stack2.empty()) {
    return false;
  } else if (stack1.size() == stack2.size()) {
    for (int i = 0; i < stack1.size(); ++i) {
      element1 = stack1.at(i);
      element2 = stack2.at(i);

      if (element1 != element2) {
        return true;
        break;
      }
    }
    return false;

  } else {
    return true;
  }
}

template <typename Type>
bool operator==(const Type& stack1, const Type& stack2) {
  auto element1 = 0, element2 = 0;

  if (stack1.empty() && stack2.empty())
    return true;

  else if (stack1.size() == stack2.size()) {
    for (int i = 0; i < stack1.size(); ++i) {
      element1 = stack1.at(i);
      element2 = stack2.at(i);

      if (element1 != element2) {
        return false;
        break;
      }
    }
    return true;
  } else {
    return false;
  }
}

template <typename Type>
Stack_List<Type> Stack_List<Type>::operator+(const Stack_List<Type>& stack1) {
  Stack_List<Type> suma;
  auto temp1 = front_;

  while (temp1 != nullptr) {
    suma.push(temp1->data);
    temp1 = temp1->next;
  }
  auto temp2 = stack1.front_;
  while (temp2 != nullptr) {
    suma.push(temp2->data);
    temp2 = temp2->next;
  }
  suma.size_ = size_ + stack1.size_;
  return suma;
}

template <typename Type>
const Type& Stack_List<Type>::at(size_t index) const {
  if (index >= size_) {
    throw std::out_of_range{"index invalid"};
  }

  auto temp = front_;

  for (size_t i = 0; i < index; i++) {
    temp = temp->next;
  }
  return temp->data;
}

