#pragma once
#ifndef SDDS_VANS_H
#define SDDS_VANS_H

#include "Vehicle.h"

namespace sdds{
   class Van : public Vehicle {
      std::string m_maker{};
      char m_type{};
      char m_condition{};
      char m_purpose{};
      double m_topSpeed{};
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