#pragma once
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <vector>
#include "Vehicle.h"

namespace sdds {
   class Autoshop {
      std::vector<Vehicle*> m_vehicles;
   public:
      Autoshop& operator += (Vehicle* theVehicle);
      ~Autoshop();

      void display(std::ostream& os) const;
   };
}
#endif // !SDDS_AUTOSHOP_H
