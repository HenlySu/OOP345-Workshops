#include <fstream>
#include <iomanip>
#include "CrimeStatistics.h"

namespace sdds {
   CrimeStatistics::CrimeStatistics(const char* filename) {
      std::ifstream file(filename);

   }
   void CrimeStatistics::display(std::ostream& os) const {

   }

   //Helper
   std::ostream& operator << (std::ostream& os, const Crime& theCrime) {

   }

}