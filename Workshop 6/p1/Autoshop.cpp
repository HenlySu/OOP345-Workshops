#include <iostream>
#include "Autoshop.h"

namespace sdds {

   Autoshop& Autoshop::operator += (Vehicle* theVehicle) {
      m_vehicles.push_back(theVehicle);
      return *this;
   }

   void Autoshop::display(std::ostream& os) const {
      for (size_t i = 0; i < m_vehicles.size(); i++) {
         m_vehicles[i]->display(os);
      }
   }

   Autoshop::~Autoshop(){
      for (size_t i = 0; i < m_vehicles.size(); i++) {
         delete m_vehicles[i];
         m_vehicles[i] = nullptr;
      }
   }
}