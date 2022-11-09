#pragma once
#ifndef SDDS_VANS_H
#define SDDS_VANS_H

#include"Vehicle.h"

namespace sdds {
	class Van :public Vehicle {
		std::string m_maker{};
		std::string m_type{};
		std::string m_condition{};
		std::string m_purpose{};
		double m_topSpeed{};
	public:
		Van() = default;
		Van(std::istream& is);
		
		std::string condition()const;
		std::string type() const;
		std::string usage()const;

		double topSpeed()const;
		void display(std::ostream& os)const;
	};

}

#endif // !SDDS_VANS_H