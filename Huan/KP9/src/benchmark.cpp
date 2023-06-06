#include "../include/Table.hpp"
#include <chrono>
#include <fstream>
#include <iostream>
#include <vector>
#include<algorithm>

void benchmark() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::ifstream fin;
  fin.open("../tests/tests.txt");

  Table<int64_t> test1;
  std::vector<int64_t> test2;
  int64_t number, in_int;
  fin >> number;
  std::cout << number << std::endl;

  std::cout << "sorts" << std::endl;
  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
  for (int64_t y = 0; y < number; y++) {
    fin >> in_int;
    test1.insert(in_int, "aaaaa");
  }
  test1.quickSort();
  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
  fin.clear();
  fin.seekg(0);
  fin >> in_int;
  begin = std::chrono::steady_clock::now();
  for (int64_t y = 0; y < number; y++) {
    fin >> in_int;
    test2.push_back(in_int);
  }
  sort(test2.begin(), test2.end());
  end = std::chrono::steady_clock::now();
  std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
}