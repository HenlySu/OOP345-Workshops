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

      friend std::ostream& operator << (std::ostream& os, const )
   };
}
#endif // !1
