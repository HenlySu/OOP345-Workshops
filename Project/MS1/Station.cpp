#include <iomanip>
#include "Station.h"

namespace sdds {
   Station::Station(const std::string& singleRecord) {

      //To do =====================================
   }

   const std::string& Station::getItemName() const {
      return m_name;
   }

   size_t Station::getNextSerialNumber() {
      return m_serialNum++;
   }

   size_t Station::getQuantity() {
      return m_quantity;
   }

   void Station::updateQuantity() {
      (m_quantity > 0) ? m_quantity-- : m_quantity;
   }

   void Station::display(std::ostream& os, bool full) const {
      
      //ID | NAME | SERIAL |
      os << "| " << std::setw(3) << m_id 
         << " | " << std::setw(m_widthField) << m_name 
         << " | " << std::setw(6) << m_serialNum << " | ";

      if (full) {
         //ID | NAME | SERIAL | QUANTITY | DESCRIPTION
         os << m_quantity << " | " << m_description;
      }

      os << std::endl;
   }
} 