#pragma once
#ifndef _RESTAURANT_H_
#define _RESTAURANT_H_

#include "Reservation.h"

namespace sdds {
   class Restaurant{
      Reservation** reservation;
   public:
      Restaurant(const Reservation* reservations[], size_t cnt);
      size_t size();

      friend std::ostream& operator << (std::ostream& os, const Restaurant& res);
   };
}
#endif // !_RESTAURANT_H_
