#include <iostream>
#include "Autoshop.h"

namespace sdds {
   Autoshop& Autoshop::operator += (Vehicle* theVehicle) {
      m_vehicles.push_back(theVehicle);
      return *this;
   }
   void Autoshop::display(std::ostream& os) const {
      for (int i = 0; i < m_vehicles.size(); i++) {
         m_vehicles[i]->display(os);
      }
   }
}