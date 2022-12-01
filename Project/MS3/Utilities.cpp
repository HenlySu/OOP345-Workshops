/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca
I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#include <string>
#include "Utilities.h"

namespace sdds {

   char Utilities::m_delimeter = '\0';

   //Member Functions
   void Utilities::setFieldWidth(size_t newWidth) {
      m_widthField = newWidth;
   }

   size_t Utilities::getFieldWidth() const {
      return m_widthField;
   }

   std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
      std::string line{};

      if (str[next_pos] != m_delimeter) {
         line = str.substr(next_pos, str.size());
         line = line.substr(0, line.find_first_of(m_delimeter));
         next_pos += (line.size() + 1);    

         trim(line);

         //If there is more tokens
         more = (next_pos >= str.length()) ? false : true;

         //Updates the obj width
         m_widthField = (m_widthField < line.length()) ? line.length() : m_widthField;
      }
      else {
         more = false;
         throw "Exception";
      }
      return line;
   }

   //Class Functions
   void Utilities::setDelimiter(char newDelimeter) {
      m_delimeter = newDelimeter;
   }

   char Utilities::getDelimeter() {
      return m_delimeter;
   }

   std::string& trim(std::string& str) {
      str.erase(str.find_last_not_of(' ') + 1);
      str.erase(0, str.find_first_not_of(' '));
      return str;
   }
}