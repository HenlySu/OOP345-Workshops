#include <iostream>
#include <iomanip>

#include "carads.h"

namespace sdds {
   void listArgs(int argc, char* argv[]) {
      std::cout << "Commmand Line:\n"
         << "--------------------------";
      
      for (int i = 0; i < argc; i++) {
         std::cout << i + 1 << ": " << argv[i] << std::endl;
      }
   }

   Cars::Cars() {
      carPrice = 0.0;
      carBrand[0] = '\0';
      carModel[0] = '\0';
      carYear = 0;
      carStatus = '\0';
      carPromotion = false;
   }
   void Cars::read(std::istream& is) {
      if()
   }
   void Cars::display(bool reset) {

   }
   char Cars::getStatus() {

   }
}