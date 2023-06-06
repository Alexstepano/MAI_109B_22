#include "../include/Line.hpp"

template <typename T>
Line<T>::Line(const T& key, const std::string& data): key(key), data(data) {}

template<typename T>
T Line<T>::get_key() {
    return key;
}

template<typename T>
std::string Line<T>::get_data() {
    return data;
}

template <typename T>
bool Line<T>::operator<(const Line<T> &l1) const {
    return key < l1.key;
}