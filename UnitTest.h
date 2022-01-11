#pragma once
#include <List.h>
#include <assert.h>
#include <iostream>

class UnitTest {

public:
  void Run();
};

void UnitTest::Run() {
  List<int> list;
  list.AddFirst(20);
  list.AddFirst(10);
  std::cout << "Add First: 10" << std::endl;
  list.Print();
  assert(list.GetFront()->GetValue() == 10);
  std::cout << "\nTest Successful" << std::endl;
  std::cout << "Add last: 60" << std::endl;
  list.AddLast(60);
  list.Print();
  assert(list.GetLast()->GetValue() == 60);
  std::cout << "\nTest Successful" << std::endl;
  std::cout << "Removefirst" << std::endl;
  list.AddLast(20);
  list.AddLast(10);
  list.AddLast(20);
  list.Print();
  list.RemoveFirst(20);
  std::cout << std::endl;
  list.Print();
  assert(list.GetFront()->GetValue() != 20);
  std::cout << "\nTest Successful" << std::endl;
  std::cout << "Remove last:" << std::endl;
  list.AddFirst(20);
  list.AddLast(10);
  list.Print();
  std::cout << std::endl;
  list.RemoveLast(20);
  assert(list.GetLast()->GetValue() != 20);
  list.Print();
  std::cout << "\nTest Successful" << std::endl;
  std::cout << "Capacity:" << std::endl;
  list.AddLast(30);
  list.AddLast(40);
  list.AddFirst(50);
  list.Print();
  std::cout << std::endl;
  assert(list.GetSize() == 9);
  std::cout << "size: " << list.GetSize();
  std::cout << "\nTest Successful" << std::endl;
  std::cout << "Clear list:" << std::endl;
  list.Clear();
  std::cout << "Capacity: " << list.GetSize();
  assert(list.GetSize() == 0);
  std::cout << "\nTest Successful" << std::endl;
}
