#ifndef KP_6_INCLUDE_DATABASE_HPP_
#define KP_6_INCLUDE_DATABASE_HPP_

#include "Row.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "../../KP_7/include/Vector.hpp"

class DataBase {
 public:
  DataBase();
  explicit DataBase(const std::string& file_name);
  ~DataBase();

  void print();
  void addRow(const Row &row);
  std::string findServersWorkStations(const std::string &output_file);

 private:
  std::ofstream database;
  std::string path;
  Vector<Row> table;

  void createTable();
};

#include "../src/Database.cpp"

#endif //KP_6_INCLUDE_DATABASE_HPP_
