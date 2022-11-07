#include <iostream>
#include "Luxuryvan.h"

namespace sdds {
   Luxuryvan::Luxuryvan(std::istream& in) : Van(in) {
      char character{};

      in >> std::ws;
      character = in.peek();
   
      if (character != 'e') {
         throw;
      }
      else {
         m_consumption = character;
      }
   }
   void Luxuryvan::display(std::ostream& out) const {
      Van::display(out);

      out << "electronic van *";
   }

   std::string Luxuryvan::consumption() const {
      std::string type{};
      
      if (m_consumption[0] == 'e') {
         type = "electronic";
      }
      else if (m_consumption[0] == 'g') {
         type = "gas";
      }

      return type;
   }
}