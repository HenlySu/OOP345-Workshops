/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca

I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#pragma once
#ifndef _RESTAURANT_H_
#define _RESTAURANT_H_

#include "Reservation.h"

namespace sdds {
   class Restaurant{
      Reservation** reservation{};
      size_t resCnt{};
   public:
      Restaurant(const Reservation* reservations[], size_t cnt);
      size_t size() const;

      //Rule of three
      Restaurant(const Restaurant& obj);
      Restaurant& operator = (const Restaurant& obj);
      ~Restaurant();

      //Rule of five
      Restaurant(Restaurant&& obj) noexcept;
      Restaurant& operator = (Restaurant&& obj) noexcept;

      friend std::ostream& operator << (std::ostream& os, const Restaurant& res);
   };
}
#endif // !_RESTAURANT_H_
