#include <iostream>
#include "Utilities.h"
#include "car.h"
#include "van.h"

namespace sdds {
   Vehicle* createInstance(std::istream& in) {
      std::string line{};
      Vehicle* pointer = nullptr;

      std::getline(in, line, '\n');
      trim(line);

      switch (line[0]) {

      case 'c':
      case 'C':
         pointer = new Car(in);
         break;

      case 'v':
      case 'V':
         pointer = new Van(in);
         break;
      }
      return pointer;
   }
}
