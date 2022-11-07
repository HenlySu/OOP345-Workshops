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

      if (m_type != 'p' || m_type != 'm' || m_type != 'c') {
         throw "Invalid Record";
      }

      //Purpose
      found = line.find(',');
      something = line.substr(0, found);
      trim(something);
      m_purpose = something[0];
      line.erase(0, found + 1);

      if (m_purpose != 'd' || m_purpose != 'p' || m_purpose != 'c') {
         throw "Invalid Record";
      }

      //Condition
      found = line.find(',');
      something = line.substr(0, found);
      trim(something);
      m_condition = something[0];
      line.erase(0, found + 1);

      if (m_condition == ' ') {
         m_condition = 'n';
      }

      if (m_condition != 'n' || m_condition != 'u' || m_condition != 'b') {
         throw "Invalid Record";
      }

      //Top speed
      found = line.find('\n');
      m_topSpeed = stoi(line.substr(0, found));
      line.erase(0, found + 1);
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
      os << "| " << std::setw(8) << m_maker;
      os << " | " << std::setw(12) << type();
      os << " | " << std::setw(12) << usage();
      os << " | " << std::setw(6) << condition();
      os << " | " << std::setw(6) << std::setprecision(2) << m_topSpeed;
      os << " |\n";
   }
}