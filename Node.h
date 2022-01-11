#pragma once

template <typename T> class Node {
private:
  T value;
  Node *next = nullptr;

public:
  Node(T value) : value(value){};
  void SetNext(Node *const next) { this->next = next; }

  Node *GetNext() const { return next; }

  T GetValue() const { return value; }
};
