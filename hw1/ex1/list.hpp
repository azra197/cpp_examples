#pragma once

#include <iostream>

template <typename T>
class List {
  public:
  List() = default;

  List(const List& other);
  List(List&& other);
  List& operator=(const List& other);
  List& operator=(List&& other);
  ~List();

  void push_back(const T& elem);
  void push_front(const T& elem);
  void push_back(T&& elem);
  void push_front(T&& elem);
  T pop_front();
  T pop_back();
  const T& at(size_t index) const;

  size_t Size() const { return size; }

  bool empty() const { return size == 0; }

  class iterator;

  iterator begin();

  iterator end();

  void insert(iterator it, const T& value);

  void remove(iterator it);

  private:
  struct Node {
    T data;
    Node* next_ = nullptr;
    Node* prev_ = nullptr;
  };

  Node* front_ = nullptr;
  Node* back_ = nullptr;
  size_t size;
};

template <typename T>
List<T>::List(const List& other) {
  Node* temp = other.front_;
  front_ = new Node{temp->data};
  back_ = front_;
  back_->next_ = nullptr;
  temp = temp->next_;
  while (temp != nullptr) {
    back_->next_ = new Node{temp->data};
    back_ = back_->next_;
    temp = temp->next_;
  }
  size = other.size;
}

template <typename T>
List<T>::List(List&& other) {
  *(this) = std::move(other);
}

template <typename T>
List<T>& List<T>::operator=(const List& other) {
  if (this == &other) {
    return *this;
  }
  while (front_ != nullptr) {
    Node* temp = front_;
    front_ = front_->next_;
    delete temp;
  }
  front_ = nullptr;
  back_ = nullptr;
  size = 0;
  size = other.size;
  front_ = new Node{other.front_->data};
  back_ = front_;
  auto temp = other.front_->next_;
  while (temp != nullptr) {
    back_->next_ = new Node{temp->data};
    back_ = back_->next_;
    temp = temp->next_;
  }
  return *this;
}

template <typename T>
List<T>& List<T>::operator=(List&& other) {
  while (back_ != nullptr) {
    Node* temp = front_;
    delete temp;
    front_ = front_->next_;
  }
  front_ = nullptr;
  back_ = nullptr;
  size = 0;
  size = other.size;
  front_ = other.front_;
  back_ = other.back_;
  other.front_ = nullptr;
  other.back_ = nullptr;
  return *this;
}

template <typename T>
List<T>::~List() {
  while (front_ != nullptr) {
    Node* temp = front_;
    front_ = front_->next_;
    delete temp;
  }
  size = 0;
  front_ = nullptr;
  back_ = nullptr;
}

template <typename T>
void List<T>::push_back(const T& elem) {
  back_ = new Node{elem, nullptr, back_};

  if (front_ == nullptr) {
    front_ = back_;
  } else {
    back_->prev_->next_ = back_;
  }
  size++;
}

template <typename T>
void List<T>::push_front(const T& elem) {
  front_ = new Node{elem, front_, nullptr};

  if (back_ == nullptr) {
    back_ = front_;
  } else {
    front_->next_->prev_ = front_;
  }
  size++;
}

template <typename T>
void List<T>::push_back(T&& elem) {
  back_ = new Node{std::move(elem), nullptr, back_};

  if (front_ == nullptr) {
    front_ = back_;
  } else {
    back_->prev_->next_ = back_;
  }
  size++;
}
template <typename T>
void List<T>::push_front(T&& elem) {
  front_ = new Node{std::move(elem), front_, nullptr};

  if (back_ == nullptr) {
    back_ = front_;
  } else {
    front_->next_->prev_ = front_;
  }
  size++;
}

template <typename T>
T List<T>::pop_front() {
  if (empty()) throw("I can't pop_back an element if List is empty.");

  Node* temp = front_;
  T data_ = temp->data;

  front_ = front_->next_;

  if (front_ != nullptr) {
    front_->prev_ = nullptr;
  } else {
    back_ = nullptr;
  }

  delete temp;
  return data_;
}

template <typename T>
T List<T>::pop_back() {
  if (empty()) throw("I can't pop_back an element if List is empty.");

  Node* temp = back_;
  T data_ = back_->data;
  back_ = back_->prev_;

  if (back_ != nullptr) {
    back_->next_ = nullptr;
  } else {
    front_ = nullptr;
  }

  delete temp;
  return data_;
}

template <typename T>
const T& List<T>::at(size_t index) const {
  if (index >= size) {
    throw std::out_of_range{"index invalis"};
  }
  auto temp = front_;
  for (size_t i = 0; i < index; i++) {
    temp = temp->next_;
  }
  return temp->data;
}

template <typename T>
class List<T>::iterator
    : public std::iterator<std::bidirectional_iterator_tag, T> {
  public:
  friend class List<T>;
  iterator(Node* p) : p_{p} {}

  iterator& operator++() {
    if (p_ != nullptr) p_ = p_->next_;
    return *this;
  }

  iterator operator++(int) {
    // auto temp=*this;
    auto temp = iterator{p_};
    if (p_ != nullptr) p_ = p_->next_;
    return temp;
  }

  iterator& operator--() {
    if (p_ != nullptr) p_ = p_->prev_;
    return *this;
  }

  iterator operator--(int) {
    // auto temp=*this;
    auto temp = iterator{p_};
    if (p_ != nullptr) p_ = p_->prev_;
    return temp;
  }

  bool operator==(const iterator& other) { return p_ == other.p_; }

  bool operator!=(const iterator& other) { return p_ != other.p_; }

  T& operator*() { return p_->data; }

  T& operator->() { return p_->data; }

  private:
  Node* p_;
};


template <typename T>
typename List<T>::iterator List<T>::begin() {
  if (!empty()) {
    typename List<T>::iterator it = front_;
    return it;
  }
}
template <typename T>
typename List<T>::iterator List<T>::end() {
  typename List<T>::iterator it = back_;
  return it;
}

template <typename T>
void List<T>::insert(iterator it, const T& value) {
  if (it.p_ == front_) {
    auto pp = new Node{value, front_};
    front_->prev_ = pp;
    front_ = pp;
    size++;
  } else {
    auto* pcpy = it.p_;
    auto* pp = new Node{value, pcpy, pcpy->prev_};
    pcpy->prev_->next_ = pp;
    pcpy->prev_ = pp;
    auto temp{pp};
    size++;
  }
}

template <typename T>
void List<T>::remove(iterator it) {
  auto* pcpy = it.p_;
  iterator value = pcpy->next_;
  pcpy->prev_->next_ = pcpy->next_;
  pcpy->next_->prev_ = pcpy->prev_;
  delete pcpy;
  size--;
}

