/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca

I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
#include <regex>
#include "Reservation.h"

namespace sdds {
   Reservation::Reservation() {
      reservationID = {};
      reservationName = {};
      reservationEmail = {};
      numPartyPeople = 0;
      reservationDay = 0;
      reservationHour = 0;
   }
   Reservation::Reservation(const std::string& res) {
      std::string tempString = res; //Getting rid of the const so I can work with it
      std::regex removingWhiteSpaces("\\s+"); //Regex to remove whitespaces

      tempString = std::regex_replace(tempString, removingWhiteSpaces, "");

      int starting = 0;
      char semiColon = ':';
      char comma = ',';

      //Reservation ID
      size_t found = tempString.find(semiColon);
      reservationID = tempString.substr(starting, found);
      tempString.erase(starting, found + 1);

      //Reservation Name
      found = tempString.find(comma);
      reservationName = tempString.substr(starting, found);
      tempString.erase(starting, found + 1);

      //Reservation Email
      found = tempString.find(comma);
      reservationEmail = tempString.substr(starting, found);
      tempString.erase(starting, found + 1);

      //Number of Part People
      found = tempString.find(comma);
      numPartyPeople = stoi(tempString.substr(starting, found));
      tempString.erase(starting, found + 1);

      //Reservation Day
      found = tempString.find(comma);
      reservationDay = stoi(tempString.substr(starting, found));
      tempString.erase(starting, found + 1);

      //Reservation Hour
      found = tempString.find(comma);
      reservationHour = stoi(tempString.substr(starting, found));
      tempString.erase(starting, found + 1);

   }
   void Reservation::update(int day, int time) {
      this->reservationDay = day;
      this->reservationHour = time;
   }

   std::ostream& operator << (std::ostream& os, const Reservation& obj) {

      os << "Reservation" << std::setw(10) << std::right << obj.reservationID;
      os << std::setw(20) << std::right << obj.reservationName << "  ";
      os << std::setw(20) << std::left << ("<" + obj.reservationEmail + ">");

      if (obj.reservationHour >= 6 && obj.reservationHour <= 9) {
         os << "Breakfast on day " << obj.reservationDay;
         os << "@ " << obj.reservationHour << ":00 for " << obj.numPartyPeople << "people.\n";
      }
      else if (obj.reservationHour >= 11 && obj.reservationHour <= 15) {
         os << "Lunch on day " << obj.reservationDay;
         os << "@ " << obj.reservationHour << ":00 for " << obj.numPartyPeople << "people.\n";
      }
      else if (obj.reservationHour >= 17 && obj.reservationHour <= 21) {
         os << "Dinner on day " << obj.reservationDay;
         os << "@ " << obj.reservationHour << ":00 for " << obj.numPartyPeople << "people.\n";
      }
      else {
         os << "Drinks on day " << obj.reservationDay;
         os << "@ " << obj.reservationHour << ":00 for " << obj.numPartyPeople << "people.\n";
      }
      return os;
   }
}