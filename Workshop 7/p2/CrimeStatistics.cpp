/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca

I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#include <fstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
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

      auto print = [&os](const Crime crime) { os << crime << std::endl; };

      auto countCases = std::accumulate(m_crimes.begin(), m_crimes.end(), size_t(0u), [](size_t num, const Crime crime) { return num += crime.m_numCases; });
      auto totalCases = std::accumulate(m_crimes.begin(), m_crimes.end(), size_t(0u), [](size_t num, const Crime crime) { return num += crime.m_resolved; });

      std::for_each(m_crimes.begin(), m_crimes.end(), print);

      os << std::setw(89) << std::setfill('-') << '\n';
      os << std::setfill(' ');
      os << "| " << std::setw(79) << "Total Crimes:  " << countCases << " |" << std::endl;
      os << "| " << std::setw(79) << "Total Resolved Cases:  " << totalCases << " |" << std::endl;
   }

   void CrimeStatistics::sort(std::string name) {
      if (name == "Province") {
         auto sortProvince = [](const Crime crime, const Crime crime2) { return crime.m_province < crime2.m_province; };
         std::sort(m_crimes.begin(), m_crimes.end(), sortProvince);
      }
      else if (name == "Crime") {
         auto sortCrime = [](const Crime crime, const Crime crime2) { return crime.m_crime < crime2.m_crime; };
         std::sort(m_crimes.begin(), m_crimes.end(), sortCrime);
      }
      else if (name == "Cases") {
         auto sortCases = [](const Crime crime, const Crime crime2) { return crime.m_numCases < crime2.m_numCases; };
         std::sort(m_crimes.begin(), m_crimes.end(), sortCases);
      }
      else if (name == "Resolved") {
         auto sortResolved = [](const Crime crime, const Crime crime2) { return crime.m_resolved < crime2.m_resolved; };
         std::sort(m_crimes.begin(), m_crimes.end(), sortResolved);
      }
   }

   void CrimeStatistics::cleanList() {
      auto removeToken = [](Crime& crime) { if (crime.m_crime == "[None]") { crime.m_crime.clear(); } return crime; };
      std::transform(m_crimes.begin(), m_crimes.end(), m_crimes.begin(), removeToken);
   }

   bool CrimeStatistics::inCollection(std::string name) const {
      return std::any_of(m_crimes.begin(), m_crimes.end(), [name](const Crime crime) { return crime.m_crime == name; });
   }

   std::list<Crime> CrimeStatistics::getListForProvince(std::string name) const {      
      std::list<Crime> list;
      std::copy_if(m_crimes.begin(), m_crimes.end(), std::back_inserter(list), [name](const Crime crime) { return crime.m_province == name; });

      return list;
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