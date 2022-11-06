#pragma once
#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include "Vehicle.h"

namespace sdds{
   class Car : public Vehicle{
      std::string m_maker{};
      char m_condition{};
      double m_topSpeed{};
   public:
      Car() = default;
      Car(std::istream& is);
      std::string condition() const;
      double topSpeed() const;
      void display(std::ostream& os) const;
   };
   std::string& trim(std::string& str);
}
#endif //SDDS_CAR_H