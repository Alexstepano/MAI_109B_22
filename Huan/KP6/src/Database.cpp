#include "../include/Database.hpp"
#include <iostream>
#include <string>

DataBase::DataBase::DataBase() {
  path = "../tests/database.txt";
  database.open(path, std::ios::trunc);
  if (database.is_open()) {
    createTable();
  } else {
    std::cerr << "Unable to create/open the database file." << std::endl;
  }
  database.close();
}

DataBase::DataBase(const std::string &file_name) {
  path = "../tests/" + file_name + ".txt";
  database.open(path, std::ios::trunc);
  if (database.is_open()) {
    createTable();
  } else {
    std::cerr << "Unable to create/open the database file." << std::endl;
  }
  database.close();
}

DataBase::~DataBase() {
  if (database.is_open()) {
    database.close();
  }
}

void DataBase::createTable() {
  if (database.is_open()) {
    database
        << "+---------------------+----------------+---------------------+-----------+---------------------------+----------------+---------------------+-----------------+----------------------+----------------------------+--------------------- +-------------------+"
        << std::endl;
    database
        << "| Owner Surname       | Processors     | Processor Type      | Memory    | Video Controller Type     | Video Memory   | Hard Drive Type     | Num Hard Drives | Hard Drive Memory    | Num Integrated Controllers | Num External Devices | Operating System  |"
        << std::endl;
    database
        << "+---------------------+----------------+---------------------+-----------+---------------------------+----------------+---------------------+-----------------+----------------------+----------------------------+----------------------+-------------------+"
        << std::endl;
  } else {
    std::cerr << "Unable to create/open the database file." << std::endl;
  }
}

void DataBase::print() {
  std::ifstream file(path);
  std::string line;

  while (std::getline(file, line)) {
    std::cout << line << std::endl;
  }
}

void DataBase::addRow(const Row &row) {
  database.open(path, std::ios::app);
  table.push_back(row);
  if (database.is_open()) {
    database << "| " << std::left << std::setw(20) << row.owner_surname
             << "| " << std::left << std::setw(15) << row.num_processors
             << "| " << std::left << std::setw(20) << row.processor_type
             << "| " << std::left << std::setw(10) << row.memory_sz
             << "| " << std::left << std::setw(26) << row.video_controller_type
             << "| " << std::left << std::setw(15) << row.video_memory_sz
             << "| " << std::left << std::setw(20) << row.hard_driver_type
             << "| " << std::left << std::setw(16) << row.num_hard_drivers
             << "| " << std::left << std::setw(21) << row.hard_driver_memory
             << "| " << std::left << std::setw(27) << row.num_integrated_controllers
             << "| " << std::left << std::setw(21) << row.num_external_devices
             << "| " << std::left << std::setw(17) << row.operating_system << " |" << std::endl;

    database
        << "+---------------------+----------------+---------------------+-----------+---------------------------+----------------+---------------------+-----------------+----------------------+----------------------------+----------------------+-------------------+"
        << std::endl;
    database.close();
  } else {
    std::cerr << "The database file is not open." << std::endl;
  }
}

std::string DataBase::findServersWorkStations(const std::string &output_file) {
  std::string line;

  std::ofstream output(output_file);
  output << std::left << std::setw(20) << "Owner Surname" << std::setw(15) << "Classification" << std::endl;
  output << "----------------------------------------------" << std::endl;

  for (const auto &row : table) {
    std::string owner_surname = row.owner_surname;
    size_t num_processors = row.num_processors;
    std::string processor_type = row.processor_type;
    size_t memory_sz = row.memory_sz;
    std::string hard_driver_type = row.hard_driver_type;
    std::string operating_system = row.operating_system;

    bool isServer = false;
    bool isWorkstation = false;

    if (num_processors >= 8 && memory_sz >= 32 && (processor_type == "Intel Xeon" || processor_type == "AMD EPYC")
        && (operating_system == "Windows Server" || operating_system == "Linux Server")) {
      isServer = true;
    } else if (num_processors >= 4 && memory_sz >= 16
        && (processor_type == "Intel Xeon" || processor_type == "AMD EPYC")) {
      isWorkstation = true;
    }

    if (isServer) {
      output << std::left << std::setw(20) << owner_surname;
      output << std::setw(15) << "Server" << std::endl;
    } else if (isWorkstation) {
      output << std::left << std::setw(20) << owner_surname;
      output << std::setw(15) << "Workstation" << std::endl;
    }
  }

  output.close();
  return "../tests/" + output_file + ".txt";
}
