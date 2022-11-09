#include <iomanip>
#include"Car.h"

namespace sdds
{
	Car::Car(std::istream& is) {

		std::string line{};
		std::getline(is, line);

		std::string test{};
		bool notDigit = false;

		
		delData(line, ',');						//Tag
		getData(line, m_maker, ',');			//Maker
		getData(line, m_condition, ',');		//Condition
		getData(line, test, ',');				//Top speed

		if (m_condition == "") 
			m_condition = "n";

		if (m_condition != "n" && m_condition != "u" && m_condition != "b") {
			throw std::invalid_argument("Invalid record!");
		}

		isNum(test, m_topSpeed);
	}

	std::string Car::condition() const {
		std::string condition{};

		if (m_condition == "n")
			condition = "new";

		else if (m_condition == "u")
			condition = "used";

		else if (m_condition == "b")
			condition = "broken";

		return condition;
	}

	double Car::topSpeed() const {
		return m_topSpeed; 
	}

	void Car::display(std::ostream& os) const {
		os << "| " << std::setw(10) << std::right << m_maker;
		os << " | " << std::setw(6) << std::left << condition();
		os << " | " << std::setw(6) << std::right << std::setprecision(2) << std::fixed << topSpeed();
		os << " |";
	}
}