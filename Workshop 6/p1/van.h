#pragma once
#ifndef SDDS_VANS_H
#define SDDS_VANS_H

#include "Vehicle.h"

namespace sdds{
   class Van : Vehicle {
      std::string m_maker{};
      std::string m_type{};
      char m_condition{};
      std::string m_purpose{};
      int topSpeed{};
   public:
      Van(std::istream& is);
      std::string condition() const;
      double topSpeed() const;
      std::string type() const;
      std::string usage() const;
      void display(std::ostream& os) const;
    };
}
#endif //SDDS_VANS_H