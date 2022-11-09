#include"Racecar.h"

namespace sdds {

	Racecar::Racecar(std::istream& in) : Car(in) {
		std::string line{};

		//Resets file to the beginning
		in.seekg(std::ios_base::beg);
		std::getline(in, line);

		//Deletes the useless data to be able to read booster
		for (int i = 0; i < 4; i++) {
			delData(line, ',');
		}

		m_booster = stod(line);
	}

	void Racecar::display(std::ostream& out)const {

		Car::display(out);
		out << "*";

	}

	double Racecar::topSpeed()const {
		return Car::topSpeed() * (1 + m_booster);
	}

}