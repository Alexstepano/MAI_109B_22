#ifndef TABLE_HPP_INCLUDED
#define TABLE_HPP_INCLUDED

#include "../../KP7/include/Vector.hpp"
#include "Line.hpp"

template<typename T>
class Table {
private:
    Vector<Line<T>> lines;

    void heapify(const Vector<Line<T>> &arr, int64_t n, int64_t i);
public:

    Table() = default;
    ~Table() = default;
    Vector<Line<T>>& get_lines();

    void push_back(const T &key, const std::string &data);
    void sort();
    Line<T> search(const T &key);
    template<typename U>
    friend std::ostream &operator<<(std::ostream &out, Table<U> &x);

};


#include "../src/Table.cpp"

#endif
