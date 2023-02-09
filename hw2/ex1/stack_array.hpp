#pragma once
#include <iostream>
#include "stack_interface.h"

template <typename Type>
class Stack_Array : public stack_interface<Type> {
  public:
  Stack_Array() : capacity_{100}, size_{0}, data_{new Type[capacity_]} {}

  Stack_Array(const std::size_t capacity)
      : capacity_{capacity}, size_{0}, data_{new Type[capacity_]} {}

  Stack_Array(const Stack_Array& other);

  Stack_Array(Stack_Array&& other);

  Stack_Array& operator=(const Stack_Array& other);

  Stack_Array& operator=(Stack_Array&& other);

  ~Stack_Array();

  void reallocate();

  void push(const Type& val) override;
  void push(Type&& val) override;
  Type& top() override;
  const Type& top() const override;
  void pop() override;

  size_t size() const override { return size_; }

  bool empty() const override { return size() == 0; }

  friend std::ostream& operator<<(std::ostream& out,
                                  const Stack_Array<Type>& s) {
    for (int i = 0; i < s.size_; ++i) {
      out << s.data_[i] << " ";
    }
    return out;
  }

  bool operator==(const Stack_Array<Type>& stack2);

  bool operator!=(const Stack_Array<Type>& stack2);

  Stack_Array<Type> operator+(const Stack_Array<Type>& stack2);

  private:
  size_t capacity_;
  size_t size_;
  Type* data_;
};

template <typename Type>
Stack_Array<Type>::Stack_Array(const Stack_Array& other)
    : capacity_{other.capacity_},
      size_{other.size_},
      data_{new Type[capacity_]} {
  for (size_t i = 0u; i < size_; i++) {
    data_[i] = other.data_[i];
  }
}
template <typename Type>
Stack_Array<Type>::Stack_Array(Stack_Array&& other)
    : capacity_{other.capacity_}, size_{other.size_}, data_{other.data_} {
  other.data_ = nullptr;
  other.capacity_ = other.size_ = 0;
}
template <typename Type>
Stack_Array<Type>& Stack_Array<Type>::operator=(const Stack_Array& other) {
  if (other.size_ > capacity_) {
    delete[] data_;
    capacity_ = other.capacity_;
    data_ = new Type[capacity_];
  }

  size_ = other.size_;

  for (size_t i = 0u; i < size_; i++) {
    data_[i] = other.data_[i];
  }
  return *this;
}
template <typename Type>
Stack_Array<Type>& Stack_Array<Type>::operator=(Stack_Array&& other) {
  capacity_ = other.capacity_;
  size_ = other.size_;
  std::swap(data_, other.data_);

  return *this;
}
template <typename Type>
Stack_Array<Type>::~Stack_Array() {
  delete[] data_;
  data_ = nullptr;
}

template <typename Type>
void Stack_Array<Type>::reallocate() {
  auto temp = new Type[2 * capacity_];

  for (auto i = 0; i < size_; i++) {
    temp[i] = std::move(data_[i]);
  }

  delete[] data_;

  capacity_ *= 2;
  data_ = temp;
}

template <typename Type>
void Stack_Array<Type>::push(const Type& val) {
  if (size_ == capacity_) {
    reallocate();
  }
  data_[size_++] = val;
}

template <typename Type>
void Stack_Array<Type>::push(Type&& val) {
  if (size_ == capacity_) {
    reallocate();
  }
  data_[size_++] = std::move(val);
}

template <typename Type>
Type& Stack_Array<Type>::top() {
  if (empty()) throw std::underflow_error("Empty stack");
  return data_[size_ - 1];
}

template <typename Type>
const Type& Stack_Array<Type>::top() const {
  if (empty()) throw std::underflow_error("Empty stack");
  return data_[size_ - 1];
}

template <typename Type>
void Stack_Array<Type>::pop() {
  Type temp = std::move(data_[size_ - 1]);
  size_--;
}

template <typename Type>
bool Stack_Array<Type>::operator==(const Stack_Array<Type>& stack2) {
  if (empty() && stack2.empty()) return true;

  if (size_ != stack2.size_)
    return false;
  else if (size_ == stack2.size_) {
    if (top() != stack2.top())
      return false;
    else {
      for (int i = 0; i < size_; ++i) {
        if (data_[i] != stack2.data_[i]) return false;
      }
      return true;
    }
  }
}

template <typename Type>
bool Stack_Array<Type>::operator!=(const Stack_Array<Type>& stack2) {
  if (empty() && stack2.empty()) return false;

  if (size_ != stack2.size_)
    return true;
  else if (size_ == stack2.size_) {
    if (top() != stack2.top())
      return true;
    else {
      for (int i = 0; i < size_; ++i) {
        if (data_[i] != stack2.data_[i]) return true;
      }
      return false;
    }
  }
}

template <typename Type>
Stack_Array<Type> Stack_Array<Type>::operator+(
    const Stack_Array<Type>& stack2) {
  Stack_Array<Type> suma;
  suma.data_ = new Type[size_ + stack2.size_];
  auto i = 0;
  for (; i < size_; i++) {
    suma.data_[i] = data_[i];
  }
  for (auto j = 0; j < stack2.size_; j++) {
    suma.data_[i] = stack2.data_[j];
    ++i;
  }
  suma.size_ = size_ + stack2.size_;
  return suma;
}

