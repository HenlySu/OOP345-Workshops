#pragma once
#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include "Vehicle.h"

namespace sdds{
   class Car : Vehicle{
      std::string m_maker{};
      char m_condition{};
      int m_topSpeed{};
   public:
      Car(std::istream& is);
      std::string condition() const;
      double topSpeed() const;
      void display(std::ostream& os) const;
   };
}
#endif //SDDS_CAR_H