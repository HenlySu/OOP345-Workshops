/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca
I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#pragma once
#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H

#include "Station.h"

namespace sdds {

	struct Item {
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src) {};
	};

	class CustomerOrder {
		std::string m_name{};
		std::string m_product{};
		size_t m_cntItem{};
		Item** m_lstItem{};

		static size_t m_widthField;
	public:
		CustomerOrder() = default;
		CustomerOrder(const std::string str);

		//Copy
		CustomerOrder(const CustomerOrder& customOrder);
		CustomerOrder& operator = (const CustomerOrder& customerOrder) = delete;
		
		//Move
		CustomerOrder(CustomerOrder&& customOrder) noexcept;
		CustomerOrder& operator = (CustomerOrder&& customerOrder) noexcept;
		
		//Destructor
		~CustomerOrder();

		bool isOrderFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};
}
#endif // !SDDS_CUSTOMERORDER_H
