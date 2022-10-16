/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca

I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#pragma once
#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <iostream>

namespace sdds {
   class Reservation {
      std::string reservationID{};
      std::string reservationName{};
      std::string reservationEmail{};
      int numPartyPeople{};
      int reservationDay{};
      int reservationHour{};
   public:
      Reservation();
      Reservation(const std::string& res);
      void update(int day, int time);

      friend std::ostream& operator << (std::ostream& os, const Reservation& obj);
      void trim(std::string& str);
   };
}
#endif // !SDDS_RESERVATION_H
