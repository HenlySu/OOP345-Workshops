/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca

I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#pragma once
#ifndef _CONFIRMATIONSENDER_H_
#define _CONFIRMATIONSENDER_H_

#include "Reservation.h"

namespace sdds {
   class ConfirmationSender {
      const Reservation** reservation{};
      size_t resCnt{};

      bool inArray(const Reservation& obj);
      bool inArray(const Reservation& obj, size_t& returnIndex); //Returns the index at which it was found

   public:
      //Constructor
      ConfirmationSender() = default;

      //Rule of three
      ConfirmationSender(const ConfirmationSender& obj);
      ConfirmationSender& operator = (const ConfirmationSender& obj);
      ~ConfirmationSender();

      //Rule of five
      ConfirmationSender(ConfirmationSender&& obj) noexcept;
      ConfirmationSender& operator = (ConfirmationSender&& obj) noexcept;

      ConfirmationSender& operator += (const Reservation& res);
      ConfirmationSender& operator -= (const Reservation& res);

      friend std::ostream& operator << (std::ostream& os, const ConfirmationSender& confirmationSender);
   };
}
#endif // !_CONFIRMATIONSENDER_H_
