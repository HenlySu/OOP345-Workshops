#pragma once
#ifndef SDDS_CRIMESTATISTICS_H
#define SDDS_CRIMESTATISTICS_H

#include <iostream>
#include <string>
#include <vector>
#include <list>

namespace sdds {
   class Crime {
   public:
      std::string m_province{};
      std::string m_district{};
      std::string m_crime{};
      size_t m_numCases{};
      size_t m_year{};
      size_t m_resolved{};
   };

   class CrimeStatistics {
      std::vector<Crime> m_crimes{};

      void trim(std::string& str);
   public:
      CrimeStatistics(const char* filename);
      void display(std::ostream& os) const;        //Needs update

      //Part two
      void sort(std::string name);
      void cleanList();
      bool inCollection(std::string crime) const;
      std::list<Crime> getListForProvince() const;
   };

   //Helper
   std::ostream& operator << (std::ostream& os, const Crime& theCrime);
}
#endif // SDDS_CRIMESTATISTICS_H