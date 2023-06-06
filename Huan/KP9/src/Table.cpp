#include "../include/Table.hpp"

template<typename T>
void Table<T>::insert(const T &key, const std::string &input_data) {
  keys.push_back(key);
  lines.push_back(input_data);
}

template<typename T>
void Table<T>::quickSort() {
  if (lines.empty()) {
    return;
  }
  if (lines.size() != keys.size()) {
    std::cout << "Error: Number of lines and keys should be the same." << std::endl;
    return;
  }

  Vector<int> indexes;
  indexes.push_back(0);
  indexes.push_back(lines.size() - 1);

  while (!indexes.empty()) {
    int end = indexes.back();
    indexes.pop_back();
    int start = indexes.back();
    indexes.pop_back();

    int pivotIndex = Partition(start, end);

    if (pivotIndex - 1 > start) {
      indexes.push_back(start);
      indexes.push_back(pivotIndex - 1);
    }

    if (pivotIndex + 1 < end) {
      indexes.push_back(pivotIndex + 1);
      indexes.push_back(end);
    }
  }
}

template<typename T>
int Table<T>::Partition(int start, int end) {
  T pivot = keys[end];
  int i = start - 1;

  for (int j = start; j <= end - 1; ++j) {
    if (keys[j] <= pivot) {
      ++i;
      std::swap(keys[i], keys[j]);
      std::swap(lines[i], lines[j]);
    }
  }

  std::swap(keys[i + 1], keys[end]);
  std::swap(lines[i + 1], lines[end]);

  return i + 1;
}

template<typename T>
std::string Table<T>::binarySearch(const T &key) {
  this->quickSort();
  size_t left = 0, right = keys.size();
  while (left < right) {
    size_t middle = (left + right) / 2;
    if (keys[middle] < key) {
      left = middle + 1;
    } else if (keys[middle] > key) {
      right = middle;
    } else {
      return lines[middle];
    }
  }
  if (keys[left] == key) {
    return lines[left];
  }
  return "";
}

template<typename T>
std::ostream &operator<<(std::ostream &out, Table<T> &x) {
  for (size_t y = 0; y < x.keys.size(); ++y) {
    out << x.keys[y] << " " << x.lines[y] << '\n';
  }
  out << '\n';
  return out;
}

template<typename T>
std::istream &operator>>(std::istream &in, Table<T> &x) {
  int64_t o = 0;
  in >> o;

  for (int64_t y = 0; y < o; ++y) {
    T in_key;
    std::string in_data;
    in >> in_key >> in_data;
    x.insert(in_key, in_data);
  }
  return in;
}
