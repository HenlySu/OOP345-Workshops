#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "CrimeStatistics.h"

namespace sdds {
   void CrimeStatistics::trim(std::string& str) {
      str.erase(str.find_last_not_of(' ') + 1);
      str.erase(0, str.find_first_not_of(' '));
   }

   CrimeStatistics::CrimeStatistics(const char* filename) {
      std::ifstream file(filename);
      
      std::string line{};
      Crime crime;

      if (file) {
         while (file) {
            std::getline(file, line);

            //Need to fix
            trim(crime.m_province = line.substr(0, 25));
            trim(crime.m_district = line.substr(25, 25));
            trim(crime.m_crime = line.substr(50, 50));

            crime.m_year = std::stoi(line.substr(75, 80));
            crime.m_numCases = std::stoi(line.substr(80, 85));
            crime.m_resolved = std::stoi(line.substr(85, 90));

            m_crimes.push_back(crime);
         }
      }
      else {
         //Throw error here
      }
   }
   void CrimeStatistics::display(std::ostream& os) const {

      //Lambda
      auto print = [&os](const Crime crime) { os << crime << std::endl; };

      //For each
      std::for_each(m_crimes.begin(), m_crimes.end(), print);
   }

   //Helper
   std::ostream& operator << (std::ostream& os, const Crime& theCrime) {

      os << "| " << std::setw(21) << std::left << theCrime.m_province;
      os << " | " << std::setw(15) << std::left << theCrime.m_district;
      os << " | " << std::setw(20) << std::left << theCrime.m_crime;

      os << " | " << std::setw(6) << std::right << theCrime.m_year;
      os << " | " << std::setw(4) << std::right << theCrime.m_numCases;
      os << " | " << std::setw(3) << theCrime.m_resolved;
      os << " |";

      return os;
   }   
}