#include <iostream>
#include <iomanip>

namespace sdds {

   void listArgs(int argc, char* argv[]) {
      std::cout << "Commmand Line:\n"
         << "--------------------------";
      
      for (int i = 0; i < argc; i++) {
         std::cout << i + 1 << ": " << argv[i] << std::endl;
      }
   }
}