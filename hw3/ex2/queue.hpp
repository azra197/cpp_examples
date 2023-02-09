#pragma once
#include <iostream>

template <typename T>
class Queue {
  public:
  Queue() = default;
  Queue(const std::size_t capacity);

  Queue(const Queue& other);

  Queue(Queue&& other);

  Queue& operator=(const Queue& other);
  
  Queue& operator=(Queue&& other);
  
  ~Queue();

  bool empty() const { return size_ == 0; }

  size_t size() const { return size_; }
  int capacity() const { return capacity_; }
  bool isFull() const { return (size_ == capacity_); }
  bool isEmpty() const { return (size_ == 0); }
  void reallocate();
  template <typename U>
  void push(U&& element);

  T pop();

  T& top();
  const T& top() const;

  friend std::ostream& operator<<(std::ostream& out, const Queue<T>& q) {
    for (int i = 0; i < q.size_; ++i) {
      out << q.data_[i] << " ";
    }
    return out;
  }

  private:
  std::size_t capacity_ = 100;
  std::size_t size_ = 0;
  T* data_ = new T[capacity_];
  size_t front_ = 0;
  size_t back_ = 0;
};

template <typename T>
Queue<T>::Queue(const std::size_t capacity)
    : capacity_{capacity},
      size_{0},
      data_{new T[capacity_]},
      front_{0},
      back_{0} {}

template <typename T>
Queue<T>::Queue(const Queue& other)
    : capacity_{other.capacity_}, size_{other.size_}, data_{new T[capacity_]} {
  for (size_t i = 0u; i < size_; i++) {
    data_[i] = other.data_[i];
  }
  front_ = other.front_;
  back_ = other.back_;
}

template<typename T>
Queue<T>::Queue(Queue&& other)
    : capacity_{other.capacity_},
      size_{other.size_},
      data_{other.data_},
      front_{other.front_},
      back_{other.back_} {
  other.data_ = nullptr;
  other.capacity_ = other.size_ = 0;
  other.back_ = 0;
  other.front_ = 0;
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue& other) {
  delete[] data_;

  capacity_ = other.capacity_;
  size_ = other.size_;
  data_ = new T[capacity_];
  for (size_t i = 0u; i < size_; ++i) {
    data_[i] = other.data_[i];
  }

  return *this;
}

template<typename T>
Queue<T>& Queue<T>::operator=(Queue&& other) {
  if (this == &other) return *this;

  delete[] data_;
  capacity_ = other.capacity_;
  size_ = other.size_;
  data_ = other.data_;
  other.size_ = 0;
  other.capacity_ = 0;
  other.back_ = 0;
  other.front_ = 0;
  other.data_ = nullptr;
  return *this;
}

template<typename T>
Queue<T>::~Queue() {
  delete[] data_;
  data_ = nullptr;
}

template <typename T>
void Queue<T>::reallocate() {
  auto temp = new T[2 * capacity_];

  for (auto i = 0; i < size_; i++) {
    temp[i] = std::move(data_[i]);
  }

  capacity_ *= 2;
  delete[] data_;
  data_ = temp;
}

template <typename T>
template <typename U>
void Queue<T>::push(U&& elem) {
  if (empty()) {
    data_[back_] = std::forward<U>(elem);
    ++size_;
    return;
  } else if (!isFull()) {
    back_ = (back_ + 1) % capacity_;
    data_[back_] = std::forward<U>(elem);
    ++size_;
  } else if (size_ == capacity_) {
    throw std::out_of_range("Full");
  }
}

template <typename T>
T Queue<T>::pop() {
  if (!isEmpty()) {
    int index = front_;
    front_ = (front_ + 1) % capacity_;
    --size_;
    return std::move(data_[index]);
  } else {
    throw std::out_of_range("Empty");
  }
}

template <typename T>
T& Queue<T>::top() {
  if (empty()) {
    throw std::underflow_error("Empty queue");
  } else {
    return data_[front_];
  }
}

template <typename T>
const T& Queue<T>::top() const {
  if (empty()) {
    throw std::underflow_error("Empty queue");
  } else {
    return data_[front_];
  }
}
