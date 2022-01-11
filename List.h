#pragma once
#include "Node.h"
#include <iostream>

template <typename T> class List {
private:
  Node<T> *head = nullptr;
  int capacity = 0;

public:
  List();
  List(const List &source);
  List(List &&source);
  ~List();

  List &operator=(const List &right);
  List &operator=(List &&right);

  Node<T> *GetFront() const;
  Node<T> *GetLast() const;
  void AddFirst(const T item);
  void AddLast(const T item);
  void Clear();
  unsigned int GetSize() const;
  void Print() const;
  bool RemoveFirst(const T item);
  bool RemoveLast(const T item);
};

template <typename T> Node<T> *List<T>::GetFront() const { return head; }

template <typename T> Node<T> *List<T>::GetLast() const {
  Node<T> *last = head;
  while (last->GetNext() != nullptr) {
    last = last->GetNext();
  }
  return last;
}

template <typename T> List<T> &List<T>::operator=(const List &right) {
  Node<T> *next = right.head;
  this->Clear();
  while (next != nullptr) {
    this->AddLast(next->GetValue());
    next = next->GetNext();
  }
  this->capacity = right.capacity;
  return *this;
}

template <typename T> List<T>::List() {
  //	cout << "constructor" << endl;
}

template <typename T> List<T> &List<T>::operator=(List &&right) {
  if (head != right.head) {
    this->Clear();
    head = right.head;
    capacity = right.capacity;
    right.head = nullptr;
    right.capacity = 0;
  }
  return *this;
}

template <typename T> List<T>::List(const List &source) {
  Node<T> *next = source.head;
  while (next != nullptr) {
    this->AddLast(next->GetValue());
    next = next->GetNext();
  }
  capacity = source.capacity;
  // cout << "constructor copy" << endl;
}

template <typename T>
List<T>::List(List &&source) : head(source.head), capacity(source.capacity) {
  source.head = nullptr;
  source.capacity = 0;
  // cout << "move" << endl;
}

template <typename T> void List<T>::AddFirst(const T item) {
  Node<T> *node = new Node<T>(item);
  if (head == nullptr) {
    head = node;
  } else {
    Node<T> *next = head;
    head = node;
    head->SetNext(next);
  }
  capacity += 1;
}

template <typename T> void List<T>::AddLast(const T item) {
  Node<T> *node = new Node<T>(item);
  if (head == nullptr) {
    head = node;
  } else {
    Node<T> *tail = head;
    while (tail->GetNext() != nullptr) {
      tail = tail->GetNext();
    }
    tail->SetNext(node);
  }
  capacity += 1;
}
template <typename T> void List<T>::Print() const {
  Node<T> *node = head;
  while (node != nullptr) {
    std::cout << node->GetValue() << " ";

    node = node->GetNext();
  }
}

template <typename T> unsigned int List<T>::GetSize() const { return capacity; }

template <typename T> bool List<T>::RemoveFirst(const T item) {
  bool result = false;
  Node<T> *temp = nullptr;
  Node<T> *next = head;
  if (next->GetValue() == item) {
    head = next->GetNext();
    delete next;
    result = true;
  } else {
    while (next != nullptr) {
      if (next->GetValue() != item) {
        temp = next;
        next = next->GetNext();
      } else {
        temp->SetNext(next->GetNext());
        delete next;
        result = true;
        break;
      }
    }
  }
  capacity -= 1;
  return result;
}

template <typename T> bool List<T>::RemoveLast(const T item) {
  bool result = false;
  Node<T> *temp = nullptr;
  Node<T> *next = head;
  Node<T> *remove = nullptr;
  while (next != nullptr) {
    if (next->GetValue() != item) {
      Node<T> *nextn = next->GetNext();
      if (next->GetValue() != item && nextn != nullptr &&
          nextn->GetValue() == item) {
        temp = next;
      }
      next = next->GetNext();
    } else {
      remove = next;
      next = next->GetNext();
      result = true;
    }
  }
  if (remove != nullptr) {
    temp->SetNext(remove->GetNext());
    delete remove;
  }
  capacity -= 1;
  return result;
}

template <typename T> void List<T>::Clear() {
  Node<T> *temp = nullptr;
  Node<T> *next = head;
  while (next != nullptr) {
    temp = next;
    next = next->GetNext();
    delete temp;
  }
  capacity = 0;
  head = nullptr;
}

template <typename T> List<T>::~List() {
  Node<T> *temp = nullptr;
  Node<T> *next = head;
  while (next != nullptr) {
    temp = next;
    next = next->GetNext();
    delete temp;
  }
}
