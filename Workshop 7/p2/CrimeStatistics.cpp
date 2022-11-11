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
         while (!file.eof()) {
            std::getline(file, line);

            //Need to fix
            trim(crime.m_province = line.substr(0, 25));
            trim(crime.m_district = line.substr(25, 25));
            trim(crime.m_crime = line.substr(50, 25));

            crime.m_year = std::stoi(line.substr(75, 5));
            crime.m_numCases = std::stoi(line.substr(80, 5));
            crime.m_resolved = std::stoi(line.substr(85, 5));

            m_crimes.push_back(crime);
         }
      }
      else {
         //Throw error here
         throw "ERROR: Cannot open file";
      }
   }

   void CrimeStatistics::display(std::ostream& os) const {
      //Lambda
      auto print = [&os](const Crime crime) { os << crime << std::endl; };
      std::for_each(m_crimes.begin(), m_crimes.end(), print);

      //Need to calculate total cases and resolved cases
   }

   void CrimeStatistics::sort(std::string name) {
      //Need to complete
   }

   void CrimeStatistics::cleanList() {
      //Lambda
      auto removeToken = [](Crime& crime) { if (crime.m_crime == "[None]") { crime.m_crime = ""; } };

      std::for_each(m_crimes.begin(), m_crimes.end(), removeToken);
   }

   bool CrimeStatistics::inCollection(std::string crime) const {
      auto recInCollection = [crime](const Crime crimes) { return (crimes.m_crime == crime); };

      std::for_each(m_crimes.begin(), m_crimes.end(), recInCollection);
   }

   std::list<Crime> CrimeStatistics::getListForProvince() const {
      //Need to complete
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