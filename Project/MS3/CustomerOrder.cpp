/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca
I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>

#include "CustomerOrder.h"
#include "Utilities.h"

namespace sdds {

   size_t CustomerOrder::m_widthField = 0u;

   CustomerOrder::CustomerOrder(const std::string str) {
      Utilities util;
      size_t position{};
      bool more = true;
      Item* temp = nullptr;

      m_name = util.extractToken(str, position, more);
      m_product = util.extractToken(str, position, more);
      m_cntItem = std::count(str.begin(), str.end(), util.getDelimeter()) - 1;
      
      m_lstItem = new Item*[m_cntItem];

      for (size_t i = 0; i < m_cntItem; i++) {
         temp = new Item(util.extractToken(str, position, more));
         m_lstItem[i] = std::move(temp);
      }

      m_widthField = (m_widthField < util.getFieldWidth()) ? util.getFieldWidth() : m_widthField;
   }

   //Copy
   CustomerOrder::CustomerOrder(const CustomerOrder& customOrder) {
      throw "ERROR";
   }

   //Move
   CustomerOrder::CustomerOrder(CustomerOrder&& customOrder) noexcept {
      *this = std::move(customOrder);
   }

   CustomerOrder& CustomerOrder::operator = (CustomerOrder&& customerOrder) noexcept {
      if (this != &customerOrder) {
         
         //Deleting first
         if (m_lstItem != nullptr) {
            for (size_t i = 0; i < m_cntItem; i++) {
               delete m_lstItem[i];
               m_lstItem[i] = nullptr;
            }
         }
         delete[] m_lstItem;
         m_lstItem = nullptr;

         //Copying over
         m_name = customerOrder.m_name;
         m_product = customerOrder.m_product;
         m_cntItem = customerOrder.m_cntItem;
         m_lstItem = customerOrder.m_lstItem;

         //Set to empty state
         customerOrder.m_name = '\0';
         customerOrder.m_product = '\0';
         customerOrder.m_cntItem = 0;
         customerOrder.m_lstItem = nullptr;
      }

      return *this;
   }

   //Destructor
   CustomerOrder::~CustomerOrder() {
      for (size_t i = 0; i < m_cntItem; i++) {
         delete m_lstItem[i];
         m_lstItem[i] = nullptr;
      }

      delete[] m_lstItem;
      m_lstItem = nullptr;
   }

   bool CustomerOrder::isOrderFilled() const {
      bool filled = true;

      for (size_t i = 0; i < m_cntItem; i++) {
         if (m_lstItem[i]->m_isFilled == false) {
            filled = false;
         }
      }
      return filled;
   }

   bool CustomerOrder::isItemFilled(const std::string& itemName) const {
      bool filled = true;

      for (size_t i = 0; i < m_cntItem; i++) {
         if (m_lstItem[i]->m_itemName == itemName) {
            if (m_lstItem[i]->m_isFilled == false) {
               filled = false;
            }
         }
      }
      return filled;
   }

   void CustomerOrder::fillItem(Station& station, std::ostream& os) {

      bool filled = false;

      for (size_t i = 0; i < m_cntItem; i++) {
         if (m_lstItem[i]->m_itemName == station.getItemName() && m_lstItem[i]->m_isFilled == filled) {
            if (station.getQuantity() > 0) {
               station.updateQuantity();
               m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
               m_lstItem[i]->m_isFilled = true;
               filled = true;

               os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
            } 
            else {
               os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
            }
         }
      }
   }

   void CustomerOrder::display(std::ostream& os) const { 
      os << m_name << " - " << m_product << std::endl;

      for (size_t i = 0; i < m_cntItem; i++) {
         os << "[" << std::right << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
         os << std::left << std::setw(m_widthField + 2) << std::setfill(' ') << m_lstItem[i]->m_itemName;
         os << " - ";
         os << (m_lstItem[i]->m_isFilled == true ? "FILLED" : "TO BE FILLED");
         os << std::endl;
      }
   }
}