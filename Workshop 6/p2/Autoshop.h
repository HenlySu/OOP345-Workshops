#pragma once
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include<vector>
#include<list>	
#include"Vehicle.h"

namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator+=(Vehicle* theVehicle);
		~Autoshop();

		void display(std::ostream& arg_out)const;

		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles)	{
			for (size_t i = 0; i < m_vehicles.size(); i++) {
				if (test(m_vehicles[i])) {
					vehicles.push_back(m_vehicles[i]);
				}
			}

		}
	};

}

#endif // !SDDS_AUTOSHOP_H
