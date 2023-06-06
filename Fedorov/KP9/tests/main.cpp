#include <iostream>
#include "../include/Table.hpp"
#include "../src/benchmark.cpp"

int main() {
    benchmark();

    Table<int64_t> t1;
    std::cout << "____________________________________________________" << std::endl;
    std::cout << "Table interface check:" << std::endl;
    t1.push_back(7, "Have where I have none");
    t1.push_back(1799, "You might never find your place");
    t1.push_back(11, "They'll just steer your wrong");
    t1.push_back(3141592653589, "You will wake up and realize");
    t1.push_back(1814, "In the time that remains");
    t1.push_back(8, "Don't let your demons drive");
    t1.push_back(1870, "So if tomorrow never comes");
    t1.push_back(13, "You won't get out alive");
    t1.push_back(314159265, "The mistakes I've made along the way");
    t1.push_back(1903, "From living fast and dying young");
    t1.push_back(31415926535, "The time is gonna come");
    t1.push_back(146, "You can't rewind to yesterday");
    t1.push_back(1920, "I hope the best is yet to come");
    t1.push_back(3141592, "Don't get me wrong");
    t1.push_back(6, "Win where I have lost");
    t1.push_back(314159265358979, "Just how fast your life goes by");
    t1.push_back(1922, "In the time that remains for you");
    t1.push_back(2, "Don't do as I have done");
    t1.push_back(15, "Because you can't unlive the pain");


    t1.sort();
    std::cout << "Table contents" << std::endl;
    std::cout << "key\t|\tvalue" << std::endl;
    std::cout << t1 << std::endl;

    for (int64_t i: {1920, 1946}) {
        auto search_res = t1.search(i);
        if (search_res.get_data() != "\0") {
            std::cout << "Object with key '" << search_res.get_key()
                      << "' found! Data inside is '" << search_res.get_data()
                      << "'" << std::endl;
        } else {
            std::cout << "Object with key '" << search_res.get_key()
                      << "' not found!" << std::endl;
        }
    }

    return 0;
}
