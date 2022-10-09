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
      const Reservation** reservation;
   public:
      ConfirmationSender& operator += (const Reservation& res);
      ConfirmationSender& operator -= (const Reservation& res);

      friend std::ostream& operator << (std::ostream& os, const ConfirmationSender& confirmationSender);
   };
}
#endif // !1
