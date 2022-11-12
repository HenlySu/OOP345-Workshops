#include "Utilities.h"

namespace sdds {
   //Member Functions
   void Utilities::setFieldWidth(size_t newWidth) {
      m_widthField = newWidth;
   }

   size_t Utilities::getFieldWidth() const {
      return m_widthField;
   }

   std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
      
      std::string line{};

      size_t position = str.find(m_delimeter, next_pos);


   }

   //Class Functions
   void Utilities::setDelimiter(char newDelimeter) {
      m_delimeter = newDelimeter;
   }

   char Utilities::getDelimeter() {
      return m_delimeter;
   }
}