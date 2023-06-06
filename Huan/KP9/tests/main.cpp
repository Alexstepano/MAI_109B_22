#include "../include/Table.hpp"
#include "../src/benchmark.cpp"
#include <cstdint>
#include <iostream>

int main() {
  benchmark();
  Table<std::string> t;
  t.insert("aaaaa", "aaa2");
  t.insert("zacaf", "aaa2234");
  t.insert("aacaf", "aaa221");
  t.insert("aabal", "aaa233456");

  std::cout << "\nt:\n" << t << "t after sort:\n";
  t.quickSort();
  std::cout << t;

  std::cout << "Binary search by key:\naacaf: " << t.binarySearch("aacaf") << std::endl;
  std::cout << "aacak: " << t.binarySearch("aacak") << std::endl;
  std::cout << "aabal: " << t.binarySearch("aabal") << std::endl;

  Table<int64_t> t1;
  t1.insert(99, "1wasd");
  t1.insert(1, "wasd");
  t1.insert(-10, "121wasd");
  std::cout << "\nt1:\n" << t1 << "t1 after sort:\n";
  t1.quickSort();
  std::cout << t1;

  Table<std::string> t2;
  std::cout << t2;
  t2.quickSort();
  std::cout << t2;
}