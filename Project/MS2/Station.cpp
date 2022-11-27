/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca
I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

namespace sdds {

   size_t Station::m_widthField = 0u;
   size_t Station::id_generator = 0u;

   Station::Station(const std::string& singleRecord) {

      Utilities util;
      size_t position{};
      bool more = true;

      //Generate Id
      m_id = ++id_generator;

      //Extracts data from string
      m_name = util.extractToken(singleRecord, position, more);
      m_serialNum = std::stoi(util.extractToken(singleRecord, position, more));
      m_quantity = std::stoi(util.extractToken(singleRecord, position, more));

      //Updates the width before extracting description
      m_widthField = m_widthField > util.getFieldWidth() ? m_widthField : util.getFieldWidth();

      m_description = util.extractToken(singleRecord, position, more);
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
      os << std::setw(3) << std::right << std::setfill('0') << m_id << std::setfill(' ')
         << " | " << std::setw(m_widthField) << std::left << m_name
         << "  | " << std::setw(6) << std::setfill('0') << std::right << m_serialNum << " | ";

      if (full) {
         //ID | NAME | SERIAL | QUANTITY | DESCRIPTION
         os << std::setfill(' ') << std::setw(4) << std::right << m_quantity
            << std::left << " | " << m_description;
      }
      os << std::endl;
   }
}