#include <iostream>
#include <string>
#include "../include/Database.hpp"


int main() {
  DataBase database("MyDatabase");

  Row row1("Adam Smith", 4, "Intel Core i7", 16, "NVIDIA GeForce GTX 1660 Ti", 6, "SSD", 1, 512, 2, 4, "Windows 10");
  Row row2("Nguyen Valentin", 8, "Intel Xeon", 32, "AMD Radeon RX 6900 XT", 12, "HDD", 2, 1000, 3, 6, "Windows Server");
  Row row3("John Doe", 8, "Intel Xeon", 32, "NVIDIA", 4, "SSD", 2, 500, 2, 3, "Linux Server");
  Row row4("Jane Smith", 4, "Intel Xeon", 16, "NVIDIA", 2, "SSD", 1, 500, 2, 2, "Windows 10");
  Row row5("Sarah Davis", 4, "AMD EPYC", 32, "AMD", 2, "HDD", 1, 1000, 2, 2, "Windows 10");
  Row row6("Alice Johnson", 6, "Core i5", 8, "NVIDIA", 2, "HDD", 1, 500, 2, 2, "Ubuntu 20.04");
  Row row7("Bob Smith", 4, "Core i3", 4, "Intel", 1, "HDD", 1, 250, 1, 1, "Windows 10");
  Row row8("Emily Davis", 8, "Core i7", 16, "AMD", 4, "SSD", 2, 500, 2, 2, "Linux");
  Row row9("Alex Johnson", 16, "Intel Xeon", 128, "NVIDIA", 8, "RAID", 4, 4000, 3, 6, "Windows Server");

  database.addRow(row1);
  database.addRow(row2);
  database.addRow(row3);
  database.addRow(row4);
  database.addRow(row5);
  database.addRow(row6);
  database.addRow(row7);
  database.addRow(row8);
  database.addRow(row9);
  database.addRow({"Sophia Wilson", 4, "Core i5", 8, "Intel", 2, "HDD", 1, 1000, 1, 2, "Windows 10"});

  database.print();
  std::string resultFile = database.findServersWorkStations("../tests/ServersWorkStations.txt");
}
