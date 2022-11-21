#include <iostream>
#include <string>

#include "CustomerOrder.h"
#include "Station.h"
#include "Utilities.h"

namespace sdds {

   size_t CustomerOrder::m_widthField{};

   CustomerOrder::CustomerOrder(const std::string str) {
      Utilities util;
      size_t position{};
      bool more = true;

      m_name = util.extractToken(str, position, more);
      m_product = util.extractToken(str, position, more);

      do {

      } while (more);
      

      m_widthField = (m_widthField > util.getFieldWidth()) ? util.getFieldWidth() : m_widthField;
   }

   //Move
   CustomerOrder::CustomerOrder(CustomerOrder&& customOrder) noexcept {

   }

   CustomerOrder& CustomerOrder::operator = (CustomerOrder&& customerOrder) noexcept {

   }

   //Destructor
   CustomerOrder::~CustomerOrder() {

   }

   bool CustomerOrder::isOrderFilled() const {

   }

   bool CustomerOrder::isItemFilled(const std::string& itemName) const {

   }

   void CustomerOrder::fillItem(Station& station, std::ostream& os) {

   }

   void CustomerOrder::display(std::ostream& os) const {

   }
}