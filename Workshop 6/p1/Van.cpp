#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Van.h"
#include "Car.h"

namespace sdds {
   Van::Van(std::istream& is){

      std::string line{};
      std::string tag{};
      std::string something{};
      size_t found{};

      std::getline(is, line, '\n');

      //For tag
      found = line.find(',');
      tag = line.substr(0, found);
      trim(tag);
      line.erase(0, found + 1);

      //For Maker
      found = line.find(',');
      m_maker = line.substr(0, found);
      trim(this->m_maker);
      line.erase(0, found + 1);

      //Type
      found = line.find(',');
      something = line.substr(0, found);
      trim(something);
      m_type = something[0];
      line.erase(0, found + 1);

      //Purpose
      found = line.find(',');
      something = line.substr(0, found);
      trim(something);
      m_purpose = something[0];
      line.erase(0, found + 1);

      //Condition
      found = line.find(',');
      something = line.substr(0, found);
      trim(something);
      m_condition = something[0];
      line.erase(0, found + 1);

      //Top speed
      found = line.find('\n');
      m_topSpeed = stoi(line.substr(0, found));
      line.erase(0, found + 1);
   }
   
   std::string Van::condition() const{
      std::string condition = "";

      switch (m_condition) {
      case 'n':
         condition = "new";
         break;
      case 'u':
         condition = "used";
         break;
      case 'b':
         condition = "broken";
      }

      return condition;
   }
   
   double Van::topSpeed() const {
      return m_topSpeed;
   }
   
   std::string Van::type() const {
      std::string type = "";

      switch (m_type) {
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

      switch (m_purpose) {
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
      os << "| " << std::setw(8) << std::right << m_maker;
      os << " | " << std::setw(12) << std::left << type();
      os << " | " << std::setw(12) << std::left << usage();
      os << " | " << std::setw(6) << std::left << condition();
      os << " | " << std::setw(6) << std::setprecision(2) << m_topSpeed;
      os << " |\n";
   }
}
