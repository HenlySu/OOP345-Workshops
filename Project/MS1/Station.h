#pragma once
#ifndef SDDS_STATION_H
#define SDDS_STATION_H

namespace sdds {
   class Station {
      size_t m_id{};
      std::string m_name{};
      std::string m_description{};
      size_t m_serialNum{};
      size_t m_quantity{};

      static size_t m_widthField;
      static size_t id_generator;
   public:
      Station(const std::string& singleRecord);
      const std::string& getItemName() const;
      size_t getNextSerialNumber();
      size_t getQuantity();
      void updateQuantity();
      void display(std::ostream& os, bool full) const;
   };
}
#endif // !SDDS_STATION_H
