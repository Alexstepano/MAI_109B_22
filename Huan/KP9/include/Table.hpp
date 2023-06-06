#ifndef KP9_INCLUDE_TABLE_HPP_
#define KP9_INCLUDE_TABLE_HPP_
#include "../../KP_7/include/Vector.hpp"

template<typename T>
class Table {
  Vector<T> keys;
  Vector<std::string> lines;
  int Partition(int start, int end);

 public:
  Table() = default;
  ~Table() = default;

  void insert(const T &key, const std::string &input_data);
  std::string binarySearch(const T &key);
  void quickSort();

  template<typename j>
  friend std::ostream &operator<<(std::ostream &out, Table<j> &x);
  template<typename j>
  friend std::istream &operator>>(std::istream &in, Table<j> &x);
};

#include "../src/Table.cpp"

#endif //KP9_INCLUDE_TABLE_HPP_
