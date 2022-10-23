#pragma once
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include "Vehicle.h"

namespace sdds {
   class Utilities {
      Vehicle* createInstance(std::istream& in);
   };
}
#endif // !SDDS_UTILITIES_H




