#include <iostream>
#include "Utilities.h"
#include "Car.h"
#include "Van.h"
#include "Racecar.h"
#include "Luxuryvan.h"

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

         case 'r':
         case 'R':
            pointer = new Racecar(in);
            break;

         case 'l':
         case 'L':
            pointer = new Luxuryvan(in);
            break;
      
         default:
            throw "Error in create instance";
            break;
      }
      return pointer;
   }
}
