#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Car.h"

namespace sdds {
   Car::Car(std::istream& is){

      //TAG,MAKER,CONDITION,TOP_SPEED

      std::string line{};
      std::string conditionString{};
      size_t found{};
      std::string tag{};

      std::getline(is, line, '\n');

      //For tag ------------------------------------------- Fine
      found = line.find(',');
      tag = line.substr(0, found);
      line.erase(0, found + 1);

      //Maker --------------------------------------------- Fine
      found = line.find(',');
      m_maker = line.substr(0, found);
      trim(m_maker);
      line.erase(0, found + 1);

      //Condition ----------------------------------------- Not sure
      found = line.find(',');
      conditionString = line.substr(0, found);
      trim(conditionString);
      m_condition = conditionString[0];
      line.erase(0, found + 1);

      //Top speed------------------------------------------- Fine
      found = line.find('\n');
      m_topSpeed = stoi(line.substr(0, found));
      line.erase(0, found + 1);
   }
   
   std::string Car::condition() const{
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
   
   double Car::topSpeed() const{
      return m_topSpeed;
   }
   
   void Car::display(std::ostream& os) const {
      os << "| " << std::setw(10) << m_maker;
      os << " | " << std::setw(6) << condition();
      os << " | " << std::setw(6) << std::setprecision(2) << std::fixed << m_topSpeed;
      os << " |\n";
   }

   std::string& trim(std::string& str) {
      str.erase(str.find_last_not_of(' ') + 1);
      str.erase(0, str.find_first_not_of(' '));
      return str;
   }
}