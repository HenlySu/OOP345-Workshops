/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca

I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
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

   }
   void Reservation::update(int day, int time) {

   }

   std::ostream operator << (std::ostream os, const Reservation& obj) {
   
   }
}