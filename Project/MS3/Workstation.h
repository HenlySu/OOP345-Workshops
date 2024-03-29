/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca

I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <iostream>
#include <deque>
#include "Station.h"
#include "CustomerOrder.h"

namespace sdds {
   //Global Variables
   extern std::deque<sdds::CustomerOrder> g_pending;
   extern std::deque<sdds::CustomerOrder> g_completed;
   extern std::deque<sdds::CustomerOrder> g_incomplete;

   class Workstation : public Station{
      std::deque<CustomerOrder> m_orders{};
      Workstation* m_pNextStation{};
   public:
      Workstation(std::string& str);
      void fill(std::ostream& os);
      bool attemptToMoveOrder();
      void setNextStation(Workstation* station);
      Workstation* getNextStation() const;
      void display(std::ostream& os) const;
      Workstation& operator+=(CustomerOrder&& newOrder);
   };
}
#endif // !SDDS_WORKSTATION_H
