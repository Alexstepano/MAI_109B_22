#include "../include/Table.hpp"

template<typename T>
void Table<T>::push_back(const T &key, const std::string &data) {
    lines.push_back(Line<T>(key, data));
}


template<typename U>
std::ostream &operator<<(std::ostream &out, Table<U> &x) {
    for (size_t i = 0; i < x.lines.size(); ++i) {
        out << x.lines[i].get_key() << "\t" << x.lines[i].get_data() << std::endl;
    }
    return out;
}

template<typename T>
void Table<T>::heapify(const Vector<Line<T>> &arr, int64_t n, int64_t i) {
    int64_t largest = i;
    int64_t l = 2 * i + 1;
    int64_t r = 2 * i + 2;

    if (l < n && arr[l].get_key() > arr[largest].get_key())
        largest = l;

    if (r < n && arr[r].get_key() > arr[largest].get_key())
        largest = r;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

template<typename T>
void Table<T>::sort() {
    for (int64_t i = lines.size() / 2 - 1; i >= 0; i--)
        heapify(lines, lines.size(), i);

    for (int64_t i = lines.size() - 1; i >= 0; i--) {
        std::swap(lines[0], lines[i]);
        heapify(lines, i, 0);
    }
}

template<typename T>
Line<T> Table<T>::search(const T &key) {

    size_t l = 0;
    size_t r = lines.size();

    while (l <= r) {
        size_t m = l + (r - l) / 2;
        if (lines[m].get_key() == key)
            return lines[m];
        if (lines[m].get_key() < key)
            l = m + 1;
        else
            r = m - 1;
    }
    return Line<T>(key, "\0");
}


template<typename T>
Vector<Line<T>> &Table<T>::get_lines() {
    return lines;
}

