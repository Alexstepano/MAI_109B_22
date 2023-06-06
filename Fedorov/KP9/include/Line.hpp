#ifndef LINE_HPP_INCLUDED
#define LINE_HPP_INCLUDED
#include <iostream>
#include "Table.hpp"

template<typename T>
class Table;

template <typename T>
class Line {
private:
    T key;
    std::string data;
public:

    Line() = default;
    ~Line() = default;
    T get_key();
    std::string get_data();
    Line(const T& key, const std::string& data);

    bool operator<(const Line<T>& l1) const;
};

#include "../src/Line.cpp"
#endif
