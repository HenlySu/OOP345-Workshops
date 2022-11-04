#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "van.h"

namespace sdds {
   Van::Van(std::istream& is){
   
   }
   
   std::string Van::condition() const{
      std::string condition = "";

      switch (m_condition) {
      case 'n':
         condition = "New";
         break;
      case 'u':
         condition = "Used";
         break;
      case 'b':
         condition = "Broken";
      }

      return condition;
   }
   
   double Van::topSpeed() const {
      return m_topSpeed;
   }
   
   std::string Van::type() const {
      std::string type = "";

      switch (m_condition) {
      case 'p':
         type = "pickup";
         break;
      case 'm':
         type = "mini-bus";
         break;
      case 'c':
         type = "camper";
      }

      return type;
   }
   
   std::string Van::usage() const {
      std::string type = "";

      switch (m_condition) {
      case 'd':
         type = "delivery";
         break;
      case 'p':
         type = "passenger";
         break;
      case 'c':
         type = "camping";
      }

      return type;
   }
   
   void Van::display(std::ostream& os) const {
      os << "| " << std::setw(8) << m_maker;
      os << " | " << std::setw(12) << m_type;
      os << " | " << std::setw(12) << this->usage();
      os << " | " << std::setw(6) << this->condition();
   }
}