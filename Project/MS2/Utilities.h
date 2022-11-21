#pragma once
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <iostream>

namespace sdds {
   class Utilities {
      size_t m_widthField = 1;
      static char m_delimeter;
   public:
      //Member Functions
      void setFieldWidth(size_t newWidth);
      size_t getFieldWidth() const;
      std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

      //Class Functions
      static void setDelimiter(char newDelimeter);
      static char getDelimeter();
   };
   std::string& trim(std::string& str);
}
#endif // !SDDS_UTILITIES_H
