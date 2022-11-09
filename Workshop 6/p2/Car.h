#pragma once
#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include "Vehicle.h"
#include "Utilities.h"

namespace sdds {
	class Car : public Vehicle {
		std::string m_maker{};
		std::string m_condition{};
		double m_topSpeed = 0.0;
	public:
		Car() = default;
		Car(std::istream& is);

		std::string condition() const;
		double topSpeed() const;

		void display(std::ostream& os) const;
	};
}

#endif // !SDDS_CAR_H