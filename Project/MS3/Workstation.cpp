/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca

I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#include "Workstation.h"

namespace sdds {
   //Global Variables
   std::deque<sdds::CustomerOrder> g_pending;
   std::deque<sdds::CustomerOrder> g_completed;
   std::deque<sdds::CustomerOrder> g_incomplete;

   Workstation::Workstation(std::string& str) :Station(str) { }

   void Workstation::fill(std::ostream& os) {
      if (!m_orders.empty()) {
         m_orders.front().fillItem(*this, os);
      }
   }

   bool Workstation::attemptToMoveOrder() {
      bool orderMoved = false;

      if (!m_orders.empty()) {
         if (m_orders.front().isItemFilled(getItemName()) || Station::getQuantity() == 0) {
            if (m_pNextStation) {
               *m_pNextStation += std::move(m_orders.front());
            }
            else if (!m_orders.front().isOrderFilled()) {
               g_incomplete.push_back(std::move(m_orders.front()));
            }
            else {
               g_completed.push_back(std::move(m_orders.front()));
            }

            orderMoved = true;
            m_orders.pop_front();
         }
      }
      return orderMoved;
   }

   void Workstation::setNextStation(Workstation* station) {
      m_pNextStation = station;
   }

   Workstation* Workstation::getNextStation() const {
      return m_pNextStation;
   }

   void Workstation::display(std::ostream& os) const {
      if (m_pNextStation) {
         os << Station::getItemName() << " --> " << m_pNextStation->getItemName() << std::endl;
      }
      else {
         os << Station::getItemName() << " --> " << "End of Line" << std::endl;
      }
   }

   Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
      m_orders.push_back(std::move(newOrder));
      return *this;
   }
}