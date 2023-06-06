#ifndef KP_6_INCLUDE_ROW_HPP_
#define KP_6_INCLUDE_ROW_HPP_

#include <iostream>
#include <string>

class Row {
  friend class DataBase;

 private:
  std::string owner_surname;
  size_t num_processors;
  std::string processor_type;
  size_t memory_sz;
  std::string video_controller_type;
  size_t video_memory_sz;
  std::string hard_driver_type;
  size_t num_hard_drivers;
  size_t hard_driver_memory;
  size_t num_integrated_controllers;
  size_t num_external_devices;
  std::string operating_system;

 public:
  Row() = default;
  Row(const std::string &owner_surname,
      const size_t &num_processors,
      const std::string &processor_type,
      const size_t &memory_sz,
      const std::string &video_controller_type,
      const size_t &video_memory_sz,
      const std::string &hard_driver_type,
      const size_t &num_hard_drivers,
      const size_t &hard_driver_memory,
      const size_t &num_integrated_controllers,
      const size_t &num_external_devices,
      const std::string &operating_system)
      : owner_surname(owner_surname),
        num_processors(num_processors),
        processor_type(processor_type),
        memory_sz(memory_sz),
        video_controller_type(video_controller_type),
        video_memory_sz(video_memory_sz),
        hard_driver_type(hard_driver_type),
        num_hard_drivers(num_hard_drivers),
        hard_driver_memory(hard_driver_memory),
        num_integrated_controllers(num_integrated_controllers),
        num_external_devices(num_external_devices),
        operating_system(operating_system) {
  }

  ~Row() = default;
};

#endif //KP_6_INCLUDE_ROW_HPP_
