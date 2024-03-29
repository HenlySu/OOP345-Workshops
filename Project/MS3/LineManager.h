/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca

I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H

#include <vector>
#include "Workstation.h"

namespace sdds {
   class LineManager {
      std::vector<Workstation*> m_activeLine{};
      size_t m_cntCustomerOrder{};
      Workstation* m_firstStation{};
   public:
      LineManager(const std::string& file, const std::vector<Workstation*>& stations);
      void reorderStations();
      bool run(std::ostream& os);
      void display(std::ostream& os) const;
   };
}
#endif // !SDDS_LINEMANAGER_H
