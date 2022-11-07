#include <iostream>
#include "Racecar.h"

namespace sdds {
   Racecar::Racecar(std::istream& in) : Car::Car(in) {
      std::string line{};

      std::getline(in, line);
      if (std::stod(line) > 0 && std::stod(line) < 1) {
         m_booster = std::stod(line);
      }
   }

   void Racecar::display(std::ostream& out) const {
      Car::display(out);
      out << '*';
   }

   double Racecar::topSpeed() const {
      return Car::topSpeed() * (1 * m_booster);
   }
}