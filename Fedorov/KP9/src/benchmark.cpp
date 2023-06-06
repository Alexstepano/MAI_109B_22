#include <chrono>
#include <fstream>
#include <iostream>
#include <algorithm>


void benchmark() {

    std::ifstream fin;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    fin.open("./tests/benchmark_test.txt",std::ios_base::in);
    Table<int64_t> test1;
    Table<int64_t> test2;
    int64_t number, in_int;
    fin >> number;
    std::cout << "Numbers in a test file: " << number << std::endl;

    std::cout << "sort() O(N * Log(N))" << std::endl;
    for (int64_t y = 0; y < number; y++) {
        fin >> in_int;
        test1.push_back(in_int, "wtijwejfgqw0ghw0ig");
        test2.push_back(in_int, "wtijwejfgqw0ghw0ig");
    }
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    test1.sort();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    std::sort(&test2.get_lines().front(), &test2.get_lines().back(), std::less<Line<int64_t>>());
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    fin.clear();
    fin.seekg(0);
    fin >> in_int;
    test1.get_lines().clear();
    test2.get_lines().clear();


    std::cout << "search() O(N * Log(N))" << std::endl;
    for (int64_t y = 0; y < number; y++) {
        fin >> in_int;
        test1.push_back(in_int, "wtijwejfgqw0ghw0ig");
        test2.push_back(in_int, "wtijwejfgqw0ghw0ig");
    }
    begin = std::chrono::steady_clock::now();
    test1.sort();
    test1.search(5953319);
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    std::sort(&test2.get_lines().front(), &test2.get_lines().back(), std::less<Line<int64_t>>());
    test2.search(5953319);
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

}
