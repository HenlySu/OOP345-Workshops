#include <iostream>
#include "Utilities.h"
#include "car.h"
#include "van.h"

namespace sdds {
   Vehicle* createInstance(std::istream& in) {
      Vehicle* pointer = nullptr;
      char character{};

      in >> std::ws;    //Discards leading whitespaces
      character = in.peek();

      switch (character) {

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
